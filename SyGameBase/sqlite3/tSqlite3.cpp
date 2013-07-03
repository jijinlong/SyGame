#include "tSqlite3.h"
#include "iostream"
#include "sstream"
namespace data{
	static bool checkTableChange(const char *createTable[],const char *name,int &index)
	{
		index = 0;
		const char *temp = createTable[index];
		while(temp && *temp)
		{
			const char * src = name;
			const char *dest = temp;
			while(*src != '\0' && *dest != '\0')
			{
				dest = temp ++;
				while (*dest != '\0' && *src != '\0' && *dest == *src)
				{
					dest++;
					src++;
				}
				if (*dest == '\0' && *src == '\0')
				{
					return true;
				}
				src = name;
				src++;
			}
			temp = createTable[index++];;
		}
		return false;
	}
	bool sqlite3DBM::init(const char *fileName)
	{
		return init(fileName,NULL);
	}
	bool sqlite3DBM::init(const char *fileName,const char *createTable[])
	{
		const char *errMsg = NULL;
		sqlite3_stmt* pStmt = NULL;
		int nResult = sqlite3_open(fileName,&sqlite);
		if (nResult != SQLITE_OK)
        	{
       		     	std::cout<<"打开数据库失败："<<sqlite3_errmsg(sqlite)<<std::endl;
           		return false;
        	}
		int nRtn = sqlite3_prepare_v2(sqlite,"select tbl_name from SQLITE_MASTER where type='table'",-1,&pStmt,&errMsg);
		if (createTable)
		{
			const char ** temp = createTable;
			while (temp && *temp)
			{
				nRtn = sqlite3_exec(sqlite,*temp,NULL,0,NULL);
				printf("\ncreate table with sql %s \n",*temp);
				temp++;
			}
		}
		nRtn = sqlite3_prepare_v2(sqlite,"select tbl_name from SQLITE_MASTER where type='table'",-1,&pStmt,&errMsg);
		if(nRtn == SQLITE_OK)
		{
			nRtn = sqlite3_step(pStmt);
			while (SQLITE_ROW == nRtn)
			{
				int nCol = sqlite3_column_count(pStmt);
				for( int i=0; i<nCol; i++)
				{
                    			const char* name = (char *)sqlite3_column_text(pStmt, i);
					int nowTableIndex = 0;
					if (createTable && checkTableChange(createTable,name,nowTableIndex))
					{
						nRtn = sqlite3_exec(sqlite,createTable[nowTableIndex],NULL,0,NULL);
						printf("\ncreate table with sql %s \n",createTable[nowTableIndex]);
						if (nRtn != SQLITE_OK)
						{
							sqlite3_close(sqlite);
							sqlite = NULL;
							sqlite3_finalize(pStmt);
							return false;
						}
					}	
					
					sqliteOPB * opb = takeTable(name);
					if (opb)
					{
						opb->tableName = name;
						// 获取字段名字
						sqlite3_stmt* pStmt = NULL;
						char buff[1023]={'\0'};
						sprintf(buff,"select * from %s",name);
						printf("now table is:%s\n",name);
						int nRtn = sqlite3_prepare_v2(sqlite,buff,-1,&pStmt,&errMsg);
						if(nRtn == SQLITE_OK)
						{
							nRtn = sqlite3_step(pStmt);
							if (SQLITE_DONE == nRtn || nRtn == SQLITE_ROW)
							{
								int nCol = sqlite3_column_count(pStmt);
								for( int i=0; i<nCol; i++)
                                				{
									const char *name = (char *)sqlite3_column_name(pStmt, i);
									std::string v_field = name;
									opb->fields.push_back(v_field);
									printf("now row is:<%s>",name?name:"null");
								}
								opb->dbm = this;
								opb->sqlite = sqlite;
							}
						}
						sqlite3_finalize(pStmt);
					}
					else
					{
					    printf("\nget table name :%s failed\n",name);
					}

				}
				nRtn = sqlite3_step(pStmt);
               		 }
			sqlite3_finalize(pStmt);
           	 }
		return true;
	}

	bool sqlite3DBM::init()
	{
		const char *errMsg = NULL;
		sqlite3_stmt* pStmt = NULL;
		int nResult = sqlite3_open("test",&sqlite);
		if (nResult != SQLITE_OK)
        {
            std::cout<<"打开数据库失败："<<sqlite3_errmsg(sqlite)<<std::endl;
            return false;
        }
		int nRtn = sqlite3_prepare_v2(sqlite,"select tbl_name from SQLITE_MASTER where type='table'",-1,&pStmt,&errMsg);
		if(nRtn == SQLITE_OK)
		{
			nRtn = sqlite3_step(pStmt);
			while (SQLITE_ROW == nRtn)
			{
				int nCol = sqlite3_column_count(pStmt);
				for( int i=0; i<nCol; i++){
                  	const char* name = (char *)sqlite3_column_text(pStmt, i);
					sqliteOPB * opb = takeTable(name);
					if (opb)
					{
						opb->tableName = name;
						// 获取字段名字
						sqlite3_stmt* pStmt = NULL;
						char buff[1023]={'\0'};
						sprintf(buff,"select * from %s",name);
						printf("now table is:%s\n",name);
						int nRtn = sqlite3_prepare_v2(sqlite,buff,-1,&pStmt,&errMsg);
						if(nRtn == SQLITE_OK)
						{
							nRtn = sqlite3_step(pStmt);
							if (SQLITE_DONE == nRtn || nRtn == SQLITE_ROW)
							{
								int nCol = sqlite3_column_count(pStmt);
								for( int i=0; i<nCol; i++)
                                {
									const char *name = (char *)sqlite3_column_name(pStmt, i);
									std::string v_field(name);
									opb->fields.push_back(v_field);
									printf("now row is:<%s>",name?name:"null");
								}
								opb->dbm = this;
								opb->sqlite = sqlite;
							}
							else{
                                printf("sqlite down error:%s\n",name);
							}
						}
						else{
                            printf("get fields failed! %s\n",name);
						}
						sqlite3_finalize(pStmt);
					}
					else
					{
					    printf("\nget table name :%s failed\n",name);
					}

                }
				nRtn = sqlite3_step(pStmt);
			}
			sqlite3_finalize(pStmt);
           	 }
        else
        {
            return false;
        }
		return true;
	}
	bool sqlite3DBM::release()
	{
		if (sqlite)
		sqlite3_close(sqlite);
		sqlite = NULL;
		return true;
	}
	bool sqliteOPB::execInsert(vCoreData *coreData)
	{
		this->coreData = coreData;
		std::stringstream ss;
		ss<<"insert into " << tableName << " (" ;
		unsigned int count,index;
		for (index = 0,count = 0; index < fields.size();++index)
		{
			if (!genBind(fields[index],NULL))
				continue;
			if (count != 0)
			{
				ss << "," << fields[count];
			}
			else
			{
				ss <<fields[count];
			}
			count ++;
		}

		if (!count) return false; // 没有数据绑定
		sqlite3_stmt *pStmt = NULL;
		ss << ") values (";
		for (unsigned int index = 0; index < count; ++index)
		{
			if (index != 0)
				ss << ",?";
			else
				ss << "?";
		}
		ss <<")";
		printf("\ninsert :%s\n",ss.str().c_str());
		int nRtn = sqlite3_prepare(sqlite,ss.str().c_str(),-1,&pStmt,0);
		if (nRtn == SQLITE_OK)
		{
			tag = STORE;
			fieldIndex = 0;
			pos = 1;
			for (unsigned int index = 0; index < fields.size();++index)
			{
				if (genBind(fields[index],pStmt))
					pos ++;
				fieldIndex ++;
			}
			fieldIndex = 0;
			pos = 0;
			tag = 0;
			nRtn = sqlite3_step(pStmt);
			if (nRtn == SQLITE_DONE)
			{
				sqlite3_finalize(pStmt);
				return true;
			}
		}
		if (pStmt)
			sqlite3_finalize(pStmt);

		return false;
	}
	/**
 	 * 绑定整型数据
 	 * */
	void sqliteOPB::bind(int &value,sqlite3_stmt *pStmt)
	{
		if (!pStmt) return;
		if (tag == STORE)
		{
			sqlite3_bind_int(pStmt,pos,value);
		}
		else if (tag == LOAD)
		{
			value = sqlite3_column_int(pStmt,pos);
		}
	}
	/**
 	 * 绑定整型无符号数据
 	 * */
	void sqliteOPB::bind(unsigned int &value,sqlite3_stmt *pStmt)
	{
		if (!pStmt) return;
		if (tag == STORE)
		{
			sqlite3_bind_int(pStmt,pos,value);
		}
		else if (tag == LOAD)
		{
			value = sqlite3_column_int(pStmt,pos);
		}
	}
	/**
 	 * 绑定一个字符
 	 * */
	void sqliteOPB::bind(char &value,sqlite3_stmt *pStmt)
	{
		if (!pStmt) return;
		if (tag == STORE)
		{
			sqlite3_bind_int(pStmt,pos,value);
		}
		else if (tag == LOAD)
		{
			value = sqlite3_column_int(pStmt,pos);
		}
	}
	/**
 	 * 绑定一个无符号字符
 	 * */
	void sqliteOPB::bind(unsigned char &value,sqlite3_stmt *pStmt)
	{
		if (!pStmt) return;
		if (tag == STORE)
		{
			sqlite3_bind_int(pStmt,pos,value);
		}
		else if (tag == LOAD)
		{
			value = sqlite3_column_int(pStmt,pos);
		}
	}
	/**
	 * 绑定二进制串
	 * */
	void sqliteOPB::bind(unsigned char * values,unsigned int len,sqlite3_stmt *pStmt)
	{
		if (!pStmt) return;
		if (tag == STORE)
		{
			sqlite3_bind_blob(pStmt,pos,values,len,0);
		}
		else if (tag == LOAD)
		{
			const char *data = (const char *) sqlite3_column_blob(pStmt,pos);
			int tlen = sqlite3_column_bytes(pStmt,pos);
			checkValue(fields[fieldIndex],tlen);
			//if (len < tlen) tlen = len;
			bcopy(data,values,tlen);
		}
	}
	/**
 	 * 绑定字符串
 	 * */
	void sqliteOPB::bind(char *values,unsigned int len,sqlite3_stmt *pStmt)
	{
		if (!pStmt) return;
		if (tag == STORE)
		{
			sqlite3_bind_text(pStmt,pos,values,len,0);
		}
		else if (tag == LOAD)
		{
			const char * txt = (const char *) sqlite3_column_text(pStmt,pos);
			int tlen = sqlite3_column_bytes(pStmt,pos);
			if (tlen > len) tlen = len;
			strncpy(values,txt,tlen);
		}
	}
	/**
 	 * 执行选择操作
 	 * \return 成功true 失败false
 	 * */
	bool sqliteOPB::execSelect(vCoreData *coreData)
	{
		if (!dbm) return false;
		this->coreData =  coreData;
		sqlite3_stmt *pStmt = NULL;
		std::stringstream ss;
		ss << "select * from "<<tableName;
		printf("\nselect :%s\n",ss.str().c_str());
		int nRtn = sqlite3_prepare_v2(sqlite,ss.str().c_str(),-1,&pStmt,NULL);
		int dataCount = 0;
		if (nRtn == SQLITE_OK)
		{
			nRtn = sqlite3_step(pStmt);
			while (nRtn == SQLITE_ROW)
			{
				tag = LOAD;
				fieldIndex = 0;
				pos = 0;
				for (unsigned int index = 0; index < fields.size();++index)
				{
					if (genBind(fields[index],pStmt))
						pos ++;
					fieldIndex ++;
				}
				dbm->addObject(this->coreData); // 临时指针,该指针不能存储
                dataCount ++;
				fieldIndex = 0;
				pos = 0;
				tag = 0;

				nRtn = sqlite3_step(pStmt);
			}
			sqlite3_finalize(pStmt);
		}
		printf("count of data %d\n",dataCount);
		return true;
	}
	/**
 	 * 执行更新操作
 	 * \return 成功true 失败false
 	 * **/
	bool sqliteOPB::execUpdate(vCoreData *coreData)
	{
		this->coreData = coreData;
		std::stringstream ss;
		ss<<"update " << tableName << " set " ;
		unsigned int count,index;
		for (index = 0,count = 0; index < fields.size();++index)
		{
			if (!genBind(fields[index],NULL))
				continue;
			if (count != 0)
			{
				ss << "," << fields[index]<<"=?";
			}
			else
			{
				ss <<""<<fields[index]<<"=?";
			}
			count ++;
		}
		if (!count) return false; // 没有数据绑定
		sqlite3_stmt *pStmt = NULL;
		const char *keyName = getKeyName();
		if (!keyName)
		keyName = fields[0].c_str();

		ss<<" where "<<keyName<<" = ?";
		printf("update:%s\n",ss.str().c_str());

		// 执行 stmt
		int nRtn = sqlite3_prepare(sqlite,ss.str().c_str(),-1,&pStmt,0);
		if (nRtn == SQLITE_OK)
		{
			tag = STORE;
			fieldIndex = 0;
			pos = 1;
			for (unsigned int index = 0; index < fields.size();++index)
			{
				if (genBind(fields[index],pStmt))
					pos ++;
				fieldIndex ++;
			}
			std::string IndexName(keyName);
			genBind(IndexName,pStmt);
			fieldIndex = 0;
			pos = 0;
			tag = 0;
			if (nRtn == SQLITE_OK)
			{
				nRtn = sqlite3_step(pStmt);
				if (nRtn == SQLITE_DONE)
				{
					sqlite3_finalize(pStmt);
					return true;
				}
			}
		}
		sqlite3_finalize(pStmt);
		return false;
	}
};

