#include "sqlite3OO.h"
#include "string.h"
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
class ObjectManager:public data::Sqlite3DB{
public:
	virtual void addObject(data::vCoreData *data)
	{
		ObjectInTable * udata = (ObjectInTable*) data;
		udata->clear();
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