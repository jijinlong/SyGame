#pragma once
extern "C"{
#include "sqlite3.h"
}
#include "map"
#include <vector>
#include <string>
#include <sys.h>
/**
 * sqlite3 数据库操作封装
 ***/
namespace data{
#pragma pack(1)
	struct vCoreData{
		unsigned int type;  // 数据类型
		vCoreData()
		{
			type = 0;
		}
	};
#pragma pack()
	class sqlite3DBM;
	struct sqliteOPB{
		/**
 		 * 设置数据库管理对象
 		 * <code> 实现vOPData::setDBM</code>
 		 * \param dbm 当前数据管理对象
 		 * */
		virtual void setDBM(sqlite3DBM *dbm){this->dbm = dbm;}
		sqlite3DBM *dbm; // 数据库管理对象
		vCoreData *coreData; // 临时数据对象
		sqliteOPB(){dbm = NULL;}
		enum{
			STORE = 1,
			LOAD = 2,
		};
		unsigned char tag; // 当前操作类型 1 存 2 取
		int pos; // 当前stmt 有效字段位置	
		int fieldIndex; // 当前字段引索
		std::vector<std::string> fields; // 当前字段值
		std::string tableName; // 表名字
		/**
 		 * 获取当前表的关键字
 		 * \return 关键字
 		 * */
		virtual const char* getKeyName() {return NULL;}
		
		/**
 		 * 根据名字 获取绑定对象
 		 * \param name 字段名字
 		 * \param pStmt stmt 
 		 * 	要求子类实现之
 		 * 	当存在字段时 返回true
 		 * 	当不存在字段时 返回false
 		 * \return 是否存在该字段的绑定
 		 ***/
		virtual bool genBind(std::string& name,sqlite3_stmt *pStmt)= 0;
		/**
 		 * 检查长度
 		 * \param name 字段名
 		 * \param len 字段长度
 		 * **/
		virtual void checkValue(std::string & name,unsigned long len) = 0;

		/**
 		 * 绑定整型数据
 		 * */
		void bind(int &value,sqlite3_stmt *pStmt);
		/**
 		 * 绑定整型无符号数据
 		 * */		
		void bind(unsigned int &value,sqlite3_stmt *pStmt);
		/**
 		 * 绑定一个字符
 		 * */
		void bind(char &value,sqlite3_stmt *pStmt);
		/**
 		 * 绑定一个无符号字符
 		 * */
		void bind(unsigned char &value,sqlite3_stmt *pStmt);
		/**
		 * 绑定二进制串
		 * */
		void bind(unsigned char * values,unsigned int len,sqlite3_stmt *pStmt);
		/**
 		 * 绑定字符串
 		 * */
		void bind(char *values,unsigned int len,sqlite3_stmt *pStmt);
		/**
 		 * 执行插入操作
 		 * \param coreData 操作对象
 		 * \return 成功 true 失败false
 		 * **/	
		bool execInsert(vCoreData *coreData);	
		/**
 		 * 执行更新操作
 		 * \param coreData 操作的对象
 		 * \return 成功true 失败false
 		 * */
		bool execUpdate(vCoreData *coreData);
		/**
 		 * 执行获取操作
 		 * \param coreData 操作的对象
 		 * \return 成功true 失败false
 		 * */
		bool execSelect(vCoreData *coreData);
		
		sqlite3 *sqlite; // sqlite3 操作对象
	};
	/**
 	 * 数据库操作集合
 	 * */
	template<class TAOPB>
	class OPBFactory{
	public:
		/**
 		 * 对象产生器
 		 * */
		static OPBFactory &getMe()
		{
			static OPBFactory *opb = new TAOPB();
			return *opb;
		}
		/*
 		 * 获取sqlite 操作对象 一般对应于表操作
 		 * \param tableName 数据库表
 		 * \return 表操作对象
 		 * **/
		virtual sqliteOPB * getOPB(const char * tableName) {return NULL;}
	};
	/**
 	 * sqlite数据库管理
 	 * */
	class sqlite3DBM{
	public:
		sqlite3DBM()
		{
			sqlite = 0;
		}
		/**
 		 * 初始化  test 数据库
 		 * \return 成功失败
 		 * */
		bool init();
		bool init(const char *fileName);
		bool init(const char *fileName,const char *createTable[]);
		/**
 		 * 释放资源
 		 * \return 成功与否 true or false 
		 **/
		bool release();
		/**
		 * 获取表
		 * \param tableName 表名
		 * \return sqlite 表操作对象
		 * */
		virtual sqliteOPB* takeTable(const char * tableName) {return NULL;};
		/**
     		 *  资源被释放
     		 * */	
		virtual void BeReleased(){}
	
		sqlite3* sqlite; // sqlite3 句柄
		/**
 		 * 新增数据
 		 * \param data 当前数据 注意是临时对象 该指针函数执行完后 失效
 		 * **/	
		virtual void addObject(vCoreData *data){}	
	protected:
	};
	
	template <typename T>
	class tSqlite3DBM:public sqlite3DBM{
	public:
		/**
		 * 获取表名的操作对象
		 * \return sqlite3 操作表对像
		 * */
		virtual sqliteOPB* takeTable(const char *tableName)
		{
			return T::getMe().getOPB(tableName);
		}
	};	
}; // end namespace data
