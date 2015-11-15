#pragma once
#include "iostream"
using namespace std;
typedef struct ListNode *ListNodePosi;
struct ListNode {
	int Data;
	ListNodePosi pred;
	ListNodePosi succ;
};
class List
{
private:
	int _size; ListNodePosi header; ListNodePosi trailer;
protected:
	void init(); //列表创建时的初始化
public:
	List() { init(); }
	~List() {}
	ListNodePosi insertAsFirst(int e); //将e当作首节点插入
	ListNodePosi insertAsLast(int e); //将e当作末节点插入
	ListNodePosi insertAsSucc(ListNodePosi p, int e);
	//ListNodePosi insertAsSucc( char e); //将e当作p的后继插入
	ListNodePosi insertAsPred(ListNodePosi p, int e); //将e当作p的前驱插入
													  /*ListNodePosi isRemove(ListNodePosi p);*/
													  /*int remove(ListNodePosi p,ListNodePosi pt,int count);*/
	int remove(ListNodePosi p);
	ListNodePosi find(int count);
	void Print();
	bool isEmpty();
	int GetSize();
	ListNodePosi first();
};
#pragma once
