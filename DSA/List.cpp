#include <iostream>
using namespace std;
#include "list.h"
#include "stdio.h"

template <typename T>
void List<T>::init()
{

	header = new ListNode<T>; //����ͷ�ڱ��ڵ�
	trailer = new ListNode<T>; //����β�ڱ��ڵ�
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	header->Data = -1;
	trailer->Data = -1;
	_size = 0; //��¼��ģ
}

template<typename T>
ListNodePosi(T) List<T>::find(T const & e, int n, ListNodePosi(T) p) const
{
	while (0 < n--) //��0 <= n <= rank(p) < _size������p�������n��ǰ������������
		if (e == (p = p->pred)->data) return p; //����ȶԣ�ֱ�����л�ΧԽ��
	return NULL; //pԽ����߽���ζ�������ڲ���e������ʧ��
}

template <typename T>
ListNodePosi(T) List<T>::insertAsSucc(ListNodePosi(T) p, T const&e)
{
	
	ListNodePosi(T) x = new ListNode<T>; //�����½ڵ�
	x->Data = e;
	x->pred = p; x->succ = p->succ;
	p->succ->pred = x; p->succ = x; //������������
	_size++;
	return x; //�����½ڵ��λ��
};
template <typename T>
ListNodePosi(T) List<T>::insertAsPred(ListNodePosi(T) p, T const& e)
{
	ListNodePosi(T) x = new ListNode<T>; //�����½ڵ�
	x->Data = e;
	x->succ = p; x->pred = p->pred;
	p->pred->succ = x; p->pred = x; //������������
	_size++;
	return x; //�����½ڵ��λ��
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
	ListNodePosi(T) x = new ListNode<T>; //�����½ڵ�
	x->Data = e;
	x->succ = header->succ;
	x->pred = header;
	header->succ->pred = x;
	header->succ = x;
	_size++;
	return x; //�����½ڵ��λ��
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e)
{
	ListNodePosi x = new ListNode; //�����½ڵ�
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
	T e = p->data; //���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ��
	p->pred->succ = p->succ; p->succ->pred = p->pred; //��̡�ǰ��
	delete p; _size--; //�ͷŽڵ㣬���¹�ģ
	return e; //���ر��ݵ���ֵ
}



