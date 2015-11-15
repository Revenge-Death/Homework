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
	void init(); //�б���ʱ�ĳ�ʼ��
public:
	List() { init(); }
	~List() {}
	ListNodePosi insertAsFirst(int e); //��e�����׽ڵ����
	ListNodePosi insertAsLast(int e); //��e����ĩ�ڵ����
	ListNodePosi insertAsSucc(ListNodePosi p, int e);
	//ListNodePosi insertAsSucc( char e); //��e����p�ĺ�̲���
	ListNodePosi insertAsPred(ListNodePosi p, int e); //��e����p��ǰ������
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
