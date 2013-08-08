#pragma once
template<typename CLASS>
class Node{
public:
	CLASS node;
	Node<CLASS> *next;
	Node()
	{
		next = NULL;
	}
};
template<typename CLASS>
class MyList{
public:
	Node<CLASS> *readPointer;
	Node<CLASS> *writePointer;
	
	MyList()
	{
		writePointer = new Node<CLASS>();
		readPointer = writePointer;
	}
	void write(CLASS object)
	{
		if (writePointer)
		{
			writePointer->node = object;
			Node<CLASS> * node = new Node<CLASS>();
			writePointer->next = node;
			writePointer = node;
		}
	}
	bool empty()
	{
		if (readPointer == writePointer) return true;
		return false;
	}
	bool readOnly(CLASS &object)
	{
		if (empty()) return false;
		object = readPointer->node;
		return true;
	}
	bool readAndPop(CLASS &object)
	{
		if (readPointer == writePointer) return false;
		object = readPointer->node;
		Node<CLASS> * node = readPointer;
		readPointer = readPointer->next;
		delete node;
		return true;
	}
	bool pop()
	{
		if (readPointer == writePointer) return false;
		readPointer = readPointer->next;
		delete node;
		return true;
	}
	~MyList()
	{
		if (writePointer)
		{
			delete writePointer;
		}
		writePointer = NULL;
	}
};