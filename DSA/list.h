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
	ListNodePosi(T) find( int n) const;
	bool isEmpty() const { return _size <= 0; }
	int size() const { return _size; }
	ListNodePosi(T) headerNode() const { return header; }
	ListNodePosi(T) trailerNode() const { return trailer; }
	ListNodePosi(T) first();
    ListNodePosi(T) last() const;
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const; //有序区间查找

	//可写接口
	ListNodePosi(T) insertAsFirst(T const& e); //将e当作首节点插入
	ListNodePosi(T) insertAsLast(T const& e); //将e当作末节点插入
	ListNodePosi(T) insertAsSucc(ListNodePosi(T) p, T const& e);//将e当作p的后继插入
	ListNodePosi(T) insertAsPred(ListNodePosi(T) p, T const& e); //将e当作p的前驱插入
	T remove(ListNodePosi(T) p); //删除合法位置p处[将p作为参数传入前先保证其合法]的节点,返回被删除节点
	void remove(ListNodePosi(T) start, ListNodePosi(T) end,int n);//区间删除
	void insertionSort(ListNodePosi(T), int); //对从p开始连续的n个节点插入排序
	
};
#pragma once



template <typename T>void List<T>::init()
{

	header = new ListNode<T>; //创建头哨兵节点
	trailer = new ListNode<T>; //创建尾哨兵节点
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0; //记录规模
}

template<typename T>ListNodePosi(T) List<T>::find(T const & e, int n, ListNodePosi(T) p) const
{
	while (0 < n--) //（0 <= n <= rank(p) < _size）对于p的最近的n个前驱，从右向左
		if (e == (p = p->pred)->Data) return p; //逐个比对，直至命中或范围越界
	return NULL; //p越出左边界意味着区间内不含e，查找失败
}

template<typename T>inline ListNodePosi(T) List<T>::find(int n) const
{
	ListNodePosi(T) p = list->first();
	while (n--)
		p = p->succ;
	return p;
}

template <typename T>ListNodePosi(T) List<T>::insertAsSucc(ListNodePosi(T) p, T const&e)
{

	ListNodePosi(T) x = new ListNode<T>; //创建新节点
	x->Data = e;
	x->pred = p; x->succ = p->succ;
	p->succ->pred = x; p->succ = x; //设置逆向链接
	_size++;
	return x; //返回新节点的位置
};

template <typename T>ListNodePosi(T) List<T>::insertAsPred(ListNodePosi(T) p, T const& e)
{
	ListNodePosi(T) x = new ListNode<T>; //创建新节点
	x->Data = e;
	x->succ = p; x->pred = p->pred;
	p->pred->succ = x; p->pred = x; //设置逆向链接
	_size++;
	return x; //返回新节点的位置
}

template<typename T>ListNodePosi(T) List<T>::first()
{
	return headerNode()->succ;
}

template<typename T>ListNodePosi(T) List<T>::last() const
{
	return trailerNode()->pred;
}

template<typename T>ListNodePosi(T) List<T>::insertAsFirst(T const& e)
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

template <typename T>ListNodePosi(T) List<T>::insertAsLast(T const& e)
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

template <typename T>T List<T>::remove(ListNodePosi(T) p)
{
	T e = p->data; //备份待删除节点的数值（假定T类型可直接赋值）
	p->pred->succ = p->succ; p->succ->pred = p->pred; //后继、前驱
	delete p; _size--; //释放节点，更新规模
	return e; //返回备份的数值
}

template<typename T>void List<T>::remove(ListNodePosi(T) start, ListNodePosi(T) end, int n)
{
	/*ListNodePosi head = p->pred;*/
	end->succ->pred = start->pred;
	start->pred->succ = end->succ;
	/*delete p,  pl;*/ //并没有删除对应空间，这是一个隐患
	_size -= n;
}

template<typename T>
inline void List<T>::insertionSort(ListNodePosi(T), int)
{
}

template<typename T>
inline void List<T>::ReverseK(ListNodePosi(T), int k)
{
}
