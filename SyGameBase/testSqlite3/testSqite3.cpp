#include "sqlite3OO.h"
#include "string.h"
//#include "serialize.h"
class ObjectInTable:public data::TableObject{
public:
	int id;
	std::vector<unsigned char> content;
	DEC_BIND_FUNC;
	void clear()
	{
		id = 0;
		content.clear();
	}
};

IMP_BIND_FUNC_START(ObjectInTable)
{
	ObjectInTable * data = (ObjectInTable*) coreData;
	BIND_VALUE("id",data->id);
	BIND_VALUE("content",data->content);
	return true;
}
/*
class Object1:public serialize::Object{
public:
	int id;
	std::string name;
	int pos;
	IMP_SERIALIZE_DATA_FUNC()
	{
		SERIALIZE_DATA(id,0);
		SERIALIZE_DATA(name,1);
		SERIALIZE_DATA(pos,2);
	}
	void fromData(ObjectInTable &testData)
	{
		if (testData.content.size())
			parse(&testData.content[0],testData.content.size());	
	}
	void toData(ObjectInTable &testData)
	{
		store(testData.content);	 
	}

};
*/
class ObjectManager:public data::Sqlite3DB{
public:
	virtual void addObject(data::vCoreData *data)
	{
		ObjectInTable * udata = (ObjectInTable*) data;
		udata->clear();
	//	printf("get object:id:%u pos:%u name:%s\n",object.id,object.pos,object.name.c_str());
	}
};

int main()
{
	ObjectManager oM;
	oM.addTable("testtable",new ObjectInTable());
	const char * createTable[] = {
		"create table testtable(id int(10),content blob);",NULL
	};
	oM.init("test",createTable);
	oM.begin(); // 验证连接 并重新设置为有效
	data::Sqlite3Table * opb = oM.takeTable("testtable");
	if (opb)
	{
		
		ObjectInTable data;
		data.id = 1;
		data.content.resize(100);
		strcpy((char*)&data.content[0],"hello,world!");
		opb->execInsert(&data);
		data.id = 2;
		data.content.resize(100);
		strcpy((char*)&data.content[0]," say ok!");
	//	opb->execInsert(&data);
		opb->execSelect(&data);
	}
	oM.end(); // 释放连接
}