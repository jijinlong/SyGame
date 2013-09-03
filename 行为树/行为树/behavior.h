#pragma once
#include <vector>
#include <map>
#include <string>
#include "jsonObject.h"
/**
 * 系统中环境变量
 */
class Env{
public:
};
/**
 * 节点
 */
class Node{
public:
	std::string name;
	enum NODE_TYPE{
		NULL_NODE = 0,
		AND_NODE = 1,
		OR_NODE = 2,
		LEAF_NODE=3,
	};
	NODE_TYPE nodeType; // 节点类型
	Node *next; // 下一个节点
	Node *parent; // 父亲节点
	Node *child; // 子节点
	Node()
	{
		next = parent = child = NULL;
		nodeType = NULL_NODE;
		valid = true;
	}
	/**
	 * 执行
	 */
	virtual bool execute(Env *env) = 0;
	static Node *create(const std::string &name);

	void addChild(Node *child);

	bool valid; // 该节点是否有效
	bool isValid(){return valid;} // 节点开关 
#ifdef _NODE_DEBUG
	int x; // 横坐标
	int y; // 纵坐标
	std::string descInfo; // 描述信息
#endif
};
/**
* 当子节点都是True时 返回True
*/
class AndNode:public Node{
public:
	AndNode()
	{
		nodeType = AND_NODE;
	}
	/**
	 * 执行
	 */
	virtual bool execute(Env *env)
	{
		Node *temp = child;
		while (temp)
		{
			if (!temp->execute(env))
			{
				return false;
			}
			temp = temp->next;
		}
		return true;
	}
};
/**
* 当子节点有一个True时 返回True
*/
class OrNode:public Node{
public:
	OrNode()
	{
		nodeType = OR_NODE;
	}
	/**
	 * 执行
	 */
	virtual bool execute(Env *env)
	{
		Node *temp = child;
		while (temp)
		{
			if (temp->execute(env))
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
};

/**
* 条件节点 返回 True or False
*/
class LeafNode:public Node{
public:
	LeafNode()
	{
		nodeType = LEAF_NODE;
	}
	/**
	 * 执行
	 */
	virtual bool execute(Env *env)
	{
		// 执行扩展
		return false;
	}
	std::map<std::string,std::string> attrs; // 属性列表
	typedef std::map<std::string,std::string>::iterator ATTRS_ITER;
	double getDouble(const std::string &name);
	int getInt(const std::string &name);
	std::string getString(const std::string &name);
	virtual LeafNode *clone(){return NULL;}
};


template<typename LOGIC>
class LogicNode:public LeafNode{
public:
	typedef bool (LOGIC::*FUNCTION_HANDLE)(LeafNode *node,Env *env);
	FUNCTION_HANDLE handle;
	LOGIC *logic;
	/**
	 * 执行
	 */
	virtual bool execute(Env *env)
	{
		// 执行扩展
		return ((*logic).*handle)(this,env);
	}
	LogicNode(LOGIC *logic,FUNCTION_HANDLE handle):logic(logic),handle(handle){}
	virtual LeafNode *clone(){
		LogicNode<LOGIC> *obj = new LogicNode<LOGIC>(logic,handle);
		obj->name = name;
		return obj;
	}
};
/**
 * Document 从JSON 中获取节点信息 
 */
 class JSONDocument{
 public:
	JSONDocument()
	{
		root = NULL;
	}
	void parseString(const char *content);
	Node *root;
	/**
	 * 初始化逻辑体
	 */
	virtual void initLogics() = 0;
	std::map<std::string,LeafNode*> leafNodes; // 系统中的叶节点
	typedef std::map<std::string,LeafNode*>::iterator LEAF_NODES_ITER;
	bool execute(Env *env)
	{
		if (root) return root->execute(env);
		return false;
	}
	LeafNode *getLeafAction(const std::string &);
	/**
	 * 将root 重构为string
	 */
	std::string toString();
	
	void show(int x,int y)
	{
		showNode(root,x,y);
	}
	int showNode(Node *root,int x,int y)
	{
		for (int i = 0; i < x;i++) printf(".");
		printf("%s: %d %d\n",root->name.c_str(),x,y);
#ifdef _NODE_DEBUG
		root->x = x; root->y = y;
#endif
		Node *child = root->child;
		int offsety = 10;
		while (child && root->isValid())
		{
			offsety += showNode(child,x+10,y+offsety);
			child = child->next;
		}
		return offsety;
	}
	JSONObject createString(Node *root);
 };
 
 class ExampleLib:public JSONDocument{
 public:
	void initLogics()
	{
		leafNodes["sayHello"] = new LogicNode<ExampleLib>(this,&ExampleLib::sayHello);
		leafNodes["say"] = new LogicNode<ExampleLib>(this,&ExampleLib::sayHello);
	}
	bool sayHello(LeafNode *node,Env *env)
	{
		printf("hello,world %s\n",node->getString("x").c_str());
		return true;
	}
 };