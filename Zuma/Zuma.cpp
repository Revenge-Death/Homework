#include <iostream>
using namespace std;
#include <string>
#include "stdio.h"
#include "list.h"
#define _CRT_SECURE_NO_WARNINGS
List<char> *list = new List<char>();
void Print()
{
}

void isClear(ListNodePosi(char) p)
{
	while (true)
	{
		ListNodePosi mid = p;
		/*ListNodePosi mid = p;*/
		ListNodePosi firstPi = new ListNode;
		ListNodePosi lastPi = new ListNode;
		int first = 0, last = 0;
		if (_size < 3)
			break;
		while (true)
		{
			if (mid->pred != NULL && mid->Data == mid->pred->Data)

			{
				mid = mid->pred; first++;
			}
			else
			{
				firstPi = mid;
				break;
			}
		}
		while (true)
		{
			if (p->succ != NULL && p->Data == p->succ->Data)
			{
				p = p->succ; last++;
			}
			else
			{
				lastPi = p;
				break;
			}
		}
		if (last + first + 1 > 2)
		{
			int max = last + first + 1;
			p = remove(firstPi, lastPi, max);
		}
		else
			break;
	}
	return p;

}

void RePlay(ListNodePosi(char) po, long A, char B)
{
	ListNodePosi(char) p = list->find(A,list->size(),list->trailerNode);//找到插入位置
	p = list->insertAsPred(p, B);//作为前驱插入
    isClear(p);//在每次插入后判断是否需要消除
	
}
int main()
{
	string seq;
	int n;
	int *A; char *B;
	ListNodePosi(char) posi = new ListNode<char>;
	getline(cin, seq);//输入字符串
	int len = seq.size();
	for (int i = 0; i < len; i++)
		posi = list->insertAsSucc(list->headerNode, seq[i]);//一次插入后续节点值
	scanf("%ld", &n);
	A = new int[n];B = new char[n];
	for (int i = 0; i < n; i++)
		scanf("%ld %c", &A[i], &B[i]);
	for (int i = 0; i < n; i++)
		RePlay(posi, A[i], B[i]);
	return 0;
}

//ListNodePosi List::isRemove(ListNodePosi p)
//{
//	while (true)
//	{
//		ListNodePosi mid = p;
//		/*ListNodePosi mid = p;*/
//		ListNodePosi firstPi = new ListNode;
//		ListNodePosi lastPi = new ListNode;
//		int first = 0, last = 0;
//		if (_size < 3)
//			break;
//		while (true)
//		{
//			if (mid->pred != NULL && mid->Data == mid->pred->Data)
//
//			{
//				mid = mid->pred; first++;
//			}
//			else
//			{
//				firstPi = mid;
//				break;
//			}
//		}
//		while (true)
//		{
//			if (p->succ != NULL && p->Data == p->succ->Data)
//			{
//				p = p->succ; last++;
//			}
//			else
//			{
//				lastPi = p;
//				break;
//			}
//		}
//		if (last + first + 1 > 2)
//		{
//			int max = last + first + 1;
//			p = remove(firstPi, lastPi, max);
//		}
//		else
//			break;
//	}
//	return p;
//}  


//ListNodePosi List::remove(ListNodePosi p, ListNodePosi pl,int count)
//{
//	/*char e = p->Data;*/
//	ListNodePosi head = p->pred;
//	pl->succ->pred = p->pred;
//	p->pred->succ = pl->succ;
//	/*delete p,  pl;*/
//	_size -= count;
//	return head;
//}

