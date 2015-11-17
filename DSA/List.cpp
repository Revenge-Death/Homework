#include <iostream>
using namespace std;
#include "list.h"
#include "stdio.h"

template <typename T>
void List<T>::init()
{

	header = new ListNode<T>; //创建头哨兵节点
	trailer = new ListNode<T>; //创建尾哨兵节点
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	header->Data = -1;
	trailer->Data = -1;
	_size = 0; //记录规模
}

template<typename T>
ListNodePosi(T) List<T>::find(T const & e, int n, ListNodePosi(T) p) const
{
	while (0 < n--) //（0 <= n <= rank(p) < _size）对于p的最近的n个前驱，从右向左
		if (e == (p = p->pred)->data) return p; //逐个比对，直至命中或范围越界
	return NULL; //p越出左边界意味着区间内不含e，查找失败
}

template <typename T>
ListNodePosi(T) List<T>::insertAsSucc(ListNodePosi(T) p, T const&e)
{
	
	ListNodePosi(T) x = new ListNode<T>; //创建新节点
	x->Data = e;
	x->pred = p; x->succ = p->succ;
	p->succ->pred = x; p->succ = x; //设置逆向链接
	_size++;
	return x; //返回新节点的位置
};
template <typename T>
ListNodePosi(T) List<T>::insertAsPred(ListNodePosi(T) p, T const& e)
{
	ListNodePosi(T) x = new ListNode<T>; //创建新节点
	x->Data = e;
	x->succ = p; x->pred = p->pred;
	p->pred->succ = x; p->pred = x; //设置逆向链接
	_size++;
	return x; //返回新节点的位置
}

template<typename T>
ListNodePosi(T) List<T>::first() const
{
	return headerNode()->succ;
}
template<typename T>
ListNodePosi(T) List<T>::last() const
{
	return trailerNode()->pred;
}
template<typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e)
{
	ListNodePosi(T) x = new ListNode<T>; //创建新节点
	x->Data = e;
	x->succ = header->succ;
	x->pred = header;
	header->succ->pred = x;
	header->succ = x;
	_size++;
	return x; //返回新节点的位置
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e)
{
	ListNodePosi x = new ListNode; //创建新节点
	x->Data = e;
	x->pred = trailer->pred;
	x->succ = trailer;
	trailer->pred->succ = x;
	trailer->pred = x;
	_size++;
	return x;
}


template <typename T>
T List<T>::remove(ListNodePosi(T) p)
{
	T e = p->data; //备份待删除节点的数值（假定T类型可直接赋值）
	p->pred->succ = p->succ; p->succ->pred = p->pred; //后继、前驱
	delete p; _size--; //释放节点，更新规模
	return e; //返回备份的数值
}



