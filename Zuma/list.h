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
//typedef  ListNode<int>* ListNodePosi;//ע�����һ��������

template <typename T> class List //˫���б�ģ��
{
private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;//����Ĵ�С��ǰ�������
protected:
	void init(); //�б���ʱ�ĳ�ʼ��
public:
	List() { init(); }
	~List() {}
	//ֻ���ӿ�
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;
	bool isEmpty() const { return _size <= 0; };
	int size() const { return _size; }
	ListNodePosi(T) headerNode(return header) const;
	ListNodePosi(T) trailerNode(return trailer) const;
	ListNodePosi(T) first() const;
	ListNodePosi(T) last() const;

	//��д�ӿ�
	ListNodePosi(T) insertAsFirst(T const& e); //��e�����׽ڵ����
	ListNodePosi(T) insertAsLast(T const& e); //��e����ĩ�ڵ����
	ListNodePosi(T) insertAsSucc(ListNodePosi(T) p, T const& e);//��e����p�ĺ�̲���
	ListNodePosi(T) insertAsPred(ListNodePosi(T) p, T const& e); //��e����p��ǰ������
	T remove(ListNodePosi(T) p); //ɾ���Ϸ�λ��p��[��p��Ϊ��������ǰ�ȱ�֤��Ϸ�]�Ľڵ�,���ر�ɾ���ڵ�
	
};
#pragma once
