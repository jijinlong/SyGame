#pragma once
extern "C"{
#include "sqlite3.h"
}
#include "map"
#include <vector>
#include <string>
//#include <sys.h>
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
	class Sqlite3Database;
	struct Sqlite3Table{
		/**
 		 * 设置数据库管理对象
 		 * <code> 实现vOPData::setDBM</code>
 		 * \param dbm 当前数据管理对象
 		 * */
		virtual void setDBM(Sqlite3Database *dbm){this->dbm = dbm;}
		Sqlite3Database *dbm; // 数据库管理对象
		vCoreData *coreData; // 临时数据对象
		Sqlite3Table(){dbm = NULL;}
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
		virtual void checkValue(std::string & name,unsigned long len) {}

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
		 * 绑定string
		 */
		void bind(std::string &name,sqlite3_stmt *pStmt);
		/**
		 * 绑定字符串
		 */
		void bind(std::vector<unsigned char > &content,sqlite3_stmt *pStmt);
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
 	 * sqlite数据库管理
 	 * */
	class Sqlite3Database{
	public:
		std::string fileName;
		Sqlite3Database()
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
		virtual Sqlite3Table* takeTable(const char * tableName) {return NULL;};
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

		/**
		 * 尝试重置链接
		 */
		void begin();
		
		/**
		 * 结束重置链接
		 */
		void end();
	protected:
	};
	
	class Sqlite3DB:public Sqlite3Database{
	public:
		
		/**
		 * 获取表名的操作对象
		 * \return sqlite3 操作表对像
		 * */
		virtual Sqlite3Table* takeTable(const char *tableName)
		{
			TABLES_ITER iter = _tables.find(tableName);
			if (iter != _tables.end())
			{
				return iter->second;
			}
			return NULL;
		}
		/**
		 * 增加一个表
		 */
		virtual bool addTable(const char *tableName,Sqlite3Table * table)
		{
			TABLES_ITER iter = _tables.find(tableName);
			if (iter == _tables.end())
			{
				_tables[tableName] = table;
				return true;
			}
			return false;
		}
		
	private:
		std::map<std::string,Sqlite3Table*> _tables;
		typedef std::map<std::string,Sqlite3Table*>::iterator TABLES_ITER;
	};	
	/**
	 * table 对象
	 */
	class TableObject:public Sqlite3Table,public vCoreData{
	public:
	};

}; // end namespace data

#define BIND_VALUE(dname,dvalue){\
	static std::string sname = (dname);\
	if (sname == name)\
	{\
		bind((dvalue),bind_arg);\
		return true;\
	}\
}

#define BIND_STRING(dname,dvalue,dlen){\
	static std::string sname = (dname);\
	if (sname == name)\
	{\
		bind((dvalue), (dlen),bind_arg);\
		return true;\
	}\
}
#define DEC_BIND_FUNC bool genBind(std::string &name,sqlite3_stmt *bind_arg);

#define IMP_BIND_FUNC_START(__class__) bool __class__::genBind(std::string &name,sqlite3_stmt *bind_arg)

