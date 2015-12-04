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
	ListNodePosi(T) find( int n) const;
	bool isEmpty() const { return _size <= 0; }
	int size() const { return _size; }
	ListNodePosi(T) headerNode() const { return header; }
	ListNodePosi(T) trailerNode() const { return trailer; }
	ListNodePosi(T) first();
    ListNodePosi(T) last() const;
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const; //�����������

	//��д�ӿ�
	ListNodePosi(T) insertAsFirst(T const& e); //��e�����׽ڵ����
	ListNodePosi(T) insertAsLast(T const& e); //��e����ĩ�ڵ����
	ListNodePosi(T) insertAsSucc(ListNodePosi(T) p, T const& e);//��e����p�ĺ�̲���
	ListNodePosi(T) insertAsPred(ListNodePosi(T) p, T const& e); //��e����p��ǰ������
	T remove(ListNodePosi(T) p); //ɾ���Ϸ�λ��p��[��p��Ϊ��������ǰ�ȱ�֤��Ϸ�]�Ľڵ�,���ر�ɾ���ڵ�
	void remove(ListNodePosi(T) start, ListNodePosi(T) end,int n);//����ɾ��
	void insertionSort(ListNodePosi(T), int); //�Դ�p��ʼ������n���ڵ��������
	
};
#pragma once



template <typename T>void List<T>::init()
{

	header = new ListNode<T>; //����ͷ�ڱ��ڵ�
	trailer = new ListNode<T>; //����β�ڱ��ڵ�
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0; //��¼��ģ
}

template<typename T>ListNodePosi(T) List<T>::find(T const & e, int n, ListNodePosi(T) p) const
{
	while (0 < n--) //��0 <= n <= rank(p) < _size������p�������n��ǰ������������
		if (e == (p = p->pred)->Data) return p; //����ȶԣ�ֱ�����л�ΧԽ��
	return NULL; //pԽ����߽���ζ�������ڲ���e������ʧ��
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

	ListNodePosi(T) x = new ListNode<T>; //�����½ڵ�
	x->Data = e;
	x->pred = p; x->succ = p->succ;
	p->succ->pred = x; p->succ = x; //������������
	_size++;
	return x; //�����½ڵ��λ��
};

template <typename T>ListNodePosi(T) List<T>::insertAsPred(ListNodePosi(T) p, T const& e)
{
	ListNodePosi(T) x = new ListNode<T>; //�����½ڵ�
	x->Data = e;
	x->succ = p; x->pred = p->pred;
	p->pred->succ = x; p->pred = x; //������������
	_size++;
	return x; //�����½ڵ��λ��
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
	ListNodePosi(T) x = new ListNode<T>; //�����½ڵ�
	x->Data = e;
	x->succ = header->succ;
	x->pred = header;
	header->succ->pred = x;
	header->succ = x;
	_size++;
	return x; //�����½ڵ��λ��
}

template <typename T>ListNodePosi(T) List<T>::insertAsLast(T const& e)
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

template <typename T>T List<T>::remove(ListNodePosi(T) p)
{
	T e = p->data; //���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ��
	p->pred->succ = p->succ; p->succ->pred = p->pred; //��̡�ǰ��
	delete p; _size--; //�ͷŽڵ㣬���¹�ģ
	return e; //���ر��ݵ���ֵ
}

template<typename T>void List<T>::remove(ListNodePosi(T) start, ListNodePosi(T) end, int n)
{
	/*ListNodePosi head = p->pred;*/
	end->succ->pred = start->pred;
	start->pred->succ = end->succ;
	/*delete p,  pl;*/ //��û��ɾ����Ӧ�ռ䣬����һ������
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
