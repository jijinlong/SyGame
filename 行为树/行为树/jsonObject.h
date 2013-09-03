extern "C"{
#include "cJson.h"
}
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <sstream>
class JSONObject{
public:
	JSONObject(const char *text)
	{
		root =cJSON_Parse(text);
		clearTag = true;
		extData = NULL;
	}
	JSONObject()
	{
		clearTag = false;
		root=cJSON_CreateObject();
		extData = NULL;
	}
	JSONObject(cJSON *temp):root(temp)
	{
		clearTag = false;
		extData = NULL;
	}
	JSONObject &operator=(const JSONObject &object)
	{
		this->clearTag = false;
		extData = object.extData;
		root = object.root;
		return *this;
	}
	void add(const char *name,JSONObject *object)
	{
		object->clearTag = false;
		cJSON_AddItemToObject(root, name,object->root);
	}
	void add(const char *name,const char *value)
	{
		cJSON_AddStringToObject(root,name,value);
	}
	void add(const char *name,int value)
	{
		cJSON_AddNumberToObject(root,name,value);
	}
	~JSONObject()
	{
		if (clearTag)
		cJSON_Delete(root);
	}
	std::string get()
	{
		char *out=cJSON_Print(root);	
		std::string tempstr = out;
		free(out);
		return tempstr;
	}
	std::string get(const char *name)
	{
		cJSON * temp = cJSON_GetObjectItem(root,name);
		if (temp)
		{
			return temp->valuestring;
			char *out=cJSON_Print(temp);	
			std::string tempstr = out;
			free(out);
			return tempstr;
		}
		return "";
	}
	JSONObject getChild(const char *name)
	{
		JSONObject object(cJSON_GetObjectItem(root,name));
		return object;
	}
	JSONObject getChild()
	{
		JSONObject object(root->child);
		return object;
	}
	JSONObject getNext() // 获取下一个节点
	{
		JSONObject object(root->next);
		return object;
	}
	void push(JSONObject *object)
	{
		cJSON_AddItemToArray(root,object->root);
	}
	bool isValid()
	{
		return root != NULL;
	}
	std::string getText()
	{
		if (!root || !root->valuestring)
		{
			if (root->valuedouble)
			{
				std::stringstream ss;
				ss << root->valuedouble;
				return ss.str();
			}
		}
		return root->valuestring;
	}
	std::string getName()
	{
		if (!root) return "";
		return root->string;
	}
	template<typename CLASS>
	CLASS * getExt(){return (CLASS*) extData;}
	void *extData;
private:
	bool clearTag;
	cJSON *root;
};