/**
 * email:ji.jin.dragon@gmail.com
 * email:jjl_2009_hi@163.com
 * Author jijinlong
 * Data 2011.10.14~2012.3.18~~
 * All Rights Resvered
 ***/

#pragma once
/*
 * 关系型数据库 一致性映射 到内存中
 ***/
#include "vector"
#include "sys.h"
#include "type.h"
#define BYTES std::vector<char>
#include "stdio.h"
#include "string.h"
#include "sString.h"
#define BIND_VALUE(dname,dvalue){\
	static sys::sString sname = (dname);\
	if (sname == field.name)\
	{\
		bind((dvalue),bind_arg);\
		LOG_DEBUG("bind:%s value:%u",sname.str(),dvalue);\
		return true;\
	}\
}

#define BIND_STRING(dname,dvalue,dlen){\
	static sys::sString sname = (dname);\
	if (sname == field.name)\
	{\
		bind((dvalue), (dlen),bind_arg);\
		LOG_DEBUG("bind:%s len:%u",sname.str(),(dlen));\
		return true;\
	}\
}
//#define DEC_BIND_FUNC bool getBind(sys::sString &name,sqlite3_stmt *pStmt);
#define DEC_BIND_FUNC bool genBind(data::vField &field,MYSQL_BIND *bind_arg);
//#define IMP_BIND_FUNC_START (__class__) bool __class__::genBind(sys::sString &name,sqlite3_stmt *pStmt) {
#define IMP_BIND_FUNC_START(__class__) bool __class__::genBind(data::vField &field,MYSQL_BIND *bind_arg){

#define IMP_BIND_FUNC_END return false;}

namespace data{
	struct vRow;
	/**
	 * 数据存储对象需继承之
	 **/
	struct vCoreData{
		DWORD type;  // 数据类型
		vCoreData()
		{
			type = 0;
		}
	};
	/*
 	 * 字段值
 	 ***/
	struct vValue{
		BYTES value;	// 值
		/**
		 * 字段值 构造
		 * \param str 值的内容
		 **/
		vValue(const char* str)
		{
			if (str)
			{
				DWORD len = strlen(str);	
				value.resize(len+1);
				bcopy(str,&value[0],len);
			}
		}
		/**
		 * 特值化 float 的获取
		 * \return true 成功
		 **/
		bool get(float &value)
		{
			value = atof(&this->value[0]);
			return true;
		}
		/**
		 * 泛型化值的获取
		 * \return true 成功
		 **/
		template<class T>
		bool get(T&  value)
		{
			value = atoi(&this->value[0]);
			return true;
		}
		/**
		 * 获取其字符串，非字符串的获取有问题
		 **/
		char *str()
		{
			return &value[0];
		}
		/**
		 * 填充指定长度的缓存,若len 大于内容，len 为实际内容
		 * \return 成功 
		 **/
		bool get(char *bytes,DWORD& len)
		{
			if (len > value.size()) len = value.size();
			bcopy(&this->value[0],bytes,len);
			return true;
		}
		/**
		 * 获取缓存 拷贝在vector 里
		 * \return 成功
		 **/
		bool get(BYTES& bytes)
		{
			bytes.resize(value.size());
			bcopy(&value[0],&bytes[0],value.size());
			return true;
		}
	};
	/**
	 * 字段
	 **/
	struct vField{
		sys::sString name; // 字段名
		int type; // 类型
		vField(int type,const char*name)
		{
			this->type = type;
			this->name = name;
		}
		vField()
		{
			type = 0; // 类型为0
		}
	};
	
	/*
	 * vDBM 数据库操作
	 **/
	class vDBM
	{
	public:
		/**
		 * 增加物体
		 * \param data 物体指针
		 **/
		virtual void addObject(vCoreData *data) {};
		/**
		 * 初始化 使用localhost root 123456 登陆
		 * \return 成功 true 失败false
		 **/
		virtual bool init() {return false;};
		/**
		 * 资源释放
		 **/
		virtual bool release() {return false;};
		/**
		 * 初始化
		 * \param dbname 数据库名字
		 * \param username 用户名字
		 * \param pwd 密码
		 * \return 成功 true 失败false
		 **/
		virtual bool init(const char *dbname,const char *username,const char *pwd){return false;}
		/**
		 * 初始化
		 * \param dbname 数据库名字
		 * \param host 数据库地址
		 * \param username 用户名字
		 * \param pwd 密码
		 * \return 成功 true 失败false
		 **/
		virtual bool init(const char *host,const char * dbname,const char *username,const char *pwd){return false;}
	};
	/*
	 *	操作数据
	 **/
	struct vOPData{
		/**
		 * 开始表的操作
		 **/
		virtual void start() {};
		/**
		 * 数据库加载时 填充数据
		 * \param field 字段
		 * \param valeu 字段值
		 **/
		virtual void BeAttached(vField &field,vValue &value) {};
		/**
		 * 结束表的操作
		 **/
		virtual void end() {};
		/**
		 * 设置数据库管理对象
		 * \param dbm 数据库管理对象
		 **/
		virtual void setDBM(vDBM *dbm) {};
		/**
		 * 生成stmt
		 **/
		virtual void genStmt(){};
	};
	/*
 	* 每行数据
 	***/
	struct vRow{
		std::vector<vValue> values; // 数据集合
		vOPData *op; // 操作对象
		vRow()
		{
			op = 0;
		}
		/**
		 * 数据库字段 与值的赋值
		 * \param fields 字段集合
		 **/
		virtual void BeAttached(std::vector<vField>& fields)
		{
			if (values.size() != fields.size()) return;
			for (DWORD i = 0; i < fields.size();i++)
			{
				if (op)
				{
					op->BeAttached(fields[i],values[i]);
				}
			}
		}
		/**
		 * 增加字段值
		 * \param value 字段值
		 **/
		virtual void addValue(vValue &value){
			values.push_back(value);
		}
	};
	/**
 	 * 表
 	 ***/
	struct vTable{
		std::vector<vField> fields; // 字段
		std::vector<vRow> rows;	 // 行集合
		vOPData *op; // 操作对象
		const char *tableName;// 表名
		vTable()
		{
			op = 0;
			tableName = 0;
		}
		/**
		 * 开启赋值
		 **/
		virtual bool attach()
		{
			for (int rowid = 0; rowid < rows.size();++rowid)
			{
				vRow &row  = rows[rowid];
				row.op = op;
				op->start();
				row.BeAttached(fields);
				op->end();
			}
            return true;
		}
		/**
		 * 增加一行数据
		 * \param row 数据
		 **/
		virtual void addRow(vRow &row){
			rows.push_back(row);
		}
		/**
		 * 增加一个字段
		 * \param filed 字段
		 **/
		virtual void addField(vField &field){
			fields.push_back(field);
		}
	};
	/*
 	*  数据库内存对象
 	***/
	struct vDatabase{
		std::vector<vTable> tables; // 表集合
		/**
		 * 增加表项
		 * \param vTable 表
		 **/
		void addTable(vTable &table)
		{
			tables.push_back(table);
		}
		bool release()
		{
			tables.clear();
			return true;
		}
	};
}; 
