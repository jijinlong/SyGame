#include "behavior.h"


Node *Node::create(const std::string &name)
{
	Node *node = NULL;
	if (name == "and")
	{
		 node = new AndNode();
	}
	if (name == "or")
	{
		node = new OrNode();
	}
	if (node) node->name = name;
	return node;
}
void Node::addChild(Node *child)
{
	if (!this->child)
	{
		this->child = child;
	}
	else
	{
		Node *temp = this->child->next;
		Node * parent = this->child;
		while (temp)
		{
			if (!temp->next)
				parent = temp;
			temp = temp->next;
		}
		if (parent && child != this->child)
		{
			parent->next = child;
		}
	}
	child->parent = this;
}
LeafNode *JSONDocument::getLeafAction(const std::string &name)
{
	LEAF_NODES_ITER iter = leafNodes.find(name);
	if (iter != leafNodes.end())
	{
		iter->second->name = name;
		return iter->second->clone();
	}
	return NULL;
}
/**
 * {
 *    "name":"and",
 *	   "childs":[
 *	   		{
 *				"name":"sayHello",
 *			},
 *			{
 *				"name":"or",
 *				"childs":[{"name":"sayHello","content":" hello,world!"},]
 *			}
 * 	   ]	
 * }
 */
void JSONDocument::parseString(const char *content)
{
	JSONObject *object = new JSONObject(content); // 创建JSONObject 的对象
	if (!object->isValid()) return;
	std::vector<JSONObject*> nodes;
	root = Node::create(object->get("name"));
	if (!root) return;
	object->extData = root;
	nodes.push_back(object);
	while (nodes.size()) // 遍历JSON 树 获取执行节点
	{
		JSONObject& temp = *nodes.back();
		JSONObject *preDel = &temp;
		Node *parent = temp.getExt<Node>(); // 获取拓展数据
		nodes.pop_back();
		JSONObject *object = new JSONObject(temp.getChild("childs").getChild()); // 获取第一个子节点
		while (object->isValid())
		{
			std::string name = object->get("name");
			Node *node = getLeafAction(name); // 获取当前子节点
			JSONObject *preDel = NULL;
			if (!node) // 若是根节点的话 
			{
				node = Node::create(name);
				if (node)
				{
					object->extData = node;
					nodes.push_back(object); // 加入预备数据集合
				}
			}
			else
			{
				node->name = name;
				LeafNode *leafNode = (LeafNode*) node;
				// 解析Leaf的属性
				JSONObject attr = object->getChild().getNext();
				while (attr.isValid())
				{
					leafNode->attrs[attr.getName()] = attr.getText();
					attr = attr.getNext();
				}
				preDel = object;
			}
			parent->addChild(node); // 关联子节点
			object = new JSONObject(object->getNext()); // 获取下一个节点
		}
	}
}
/**
 * 将root 重构为string
 */
std::string JSONDocument::toString()
{
	// 将root 重构为Node字符串
#ifdef _NODE_DEBUG
	show(0,0);
#endif
	return createString(root).get();
}
double LeafNode::getDouble(const std::string &name)
{
	ATTRS_ITER iter = attrs.find(name);
	if (iter != attrs.end())
	{
		return atof(iter->second.c_str());
	}
	return 0;
}
int LeafNode::getInt(const std::string &name)
{
	ATTRS_ITER iter = attrs.find(name);
	if (iter != attrs.end())
	{
		return atoi(iter->second.c_str());
	}
	return 0;
}
std::string LeafNode::getString(const std::string &name)
{
	ATTRS_ITER iter = attrs.find(name);
	if (iter != attrs.end())
	{
		return iter->second.c_str();
	}
	return "";
}
JSONObject JSONDocument::createString(Node *root)
{
		if (!root) return "";
		JSONObject object;
		if (root->nodeType == Node::LEAF_NODE)
		{
			// 创建叶子节点
			object.add("name",root->name.c_str());
			LeafNode *leafNode =(LeafNode*) root;
			for (LeafNode::ATTRS_ITER iter = leafNode->attrs.begin(); iter != leafNode->attrs.end();++iter)
			{
				object.add(iter->first.c_str(),iter->second.c_str());
			}
		}
		else
		{
			// 根节点
			Node *child = root->child;
			if (root->nodeType == Node::AND_NODE)
			{
				object.add("name","and");
			}
			else
			{
				object.add("name","or");
			}
			JSONObject childs = JSONObject(cJSON_CreateArray());
			while (child)
			{
				JSONObject element = createString(child);
				childs.push(&element);
				child = child->next;
			}
			object.add("childs",&childs);
		}
		return object;
	}