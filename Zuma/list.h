#include "iostream"
using namespace std;

#define ListNodePosi(T) ListNode<T>*
template <typename T> struct ListNode {
	T Data;
	ListNodePosi(T) pred;
	ListNodePosi(T) succ;
};

//template <typename T> struct ListNode {
//	T Data;
//	ListNodePosi pred;
//	ListNodePosi succ;
//};
//typedef  ListNode<int>* ListNodePosi;//注意和上一个的区别

template <typename T> class List //双向列表模板
{
private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;//链表的大小，前驱，后继
protected:
	void init(); //列表创建时的初始化
public:
	List() { init(); }
	~List() {}
	//只读接口
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;
	bool isEmpty() const { return _size <= 0; };
	int size() const { return _size; }
	ListNodePosi(T) headerNode(return header) const;
	ListNodePosi(T) trailerNode(return trailer) const;
	ListNodePosi(T) first() const;
	ListNodePosi(T) last() const;

	//可写接口
	ListNodePosi(T) insertAsFirst(T const& e); //将e当作首节点插入
	ListNodePosi(T) insertAsLast(T const& e); //将e当作末节点插入
	ListNodePosi(T) insertAsSucc(ListNodePosi(T) p, T const& e);//将e当作p的后继插入
	ListNodePosi(T) insertAsPred(ListNodePosi(T) p, T const& e); //将e当作p的前驱插入
	T remove(ListNodePosi(T) p); //删除合法位置p处[将p作为参数传入前先保证其合法]的节点,返回被删除节点
	
};
#pragma once
