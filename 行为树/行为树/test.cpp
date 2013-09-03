#include "behavior.h"

int main()
{
	const char *content = "{\"name\":\"and\",\"childs\":\
						  [{\"name\":\"sayHello\",\"x\":10},\
						  {\"name\":\"sayHello\",\"x\":100},\
						  {\"name\":\"sayHello\",\"x\":100000},\
						  {\"name\":\"or\",\"childs\":[{\"name\":\"say\",\"x\":10}\
						  ]}\
	]}";
	ExampleLib lib;
	lib.initLogics(); // 初始化环境
	lib.parseString(content); // 解析字符串
	lib.execute(NULL); // 执行
	lib.show(10,10);
	Node *node = lib.getLeafAction("say"); // 获取当前子节点
	lib.root->addChild(node);
	/*
	 *EditAction<ExampleLib> action(lib); // 创建空树
	 *action.start(); // 展示编辑器逻辑
	 */
	printf("node:%s\n",lib.toString().c_str());

	

}