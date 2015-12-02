#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include "stdio.h"
#include "list.h"

List<char> *list = new List<char>();
void Print()
{
	if (list->size())
		printf("-\n");
	else
	{
		ListNode<char> *p = list->first();
		while (p != list->trailerNode())
		{
			printf("%c\n",p->Data);
			p = p->succ;
		}
	}
}

void isClear(ListNode<char>* p)
{
	while (true)
	{
		ListNode<char>* copyForPred = p;
		ListNode<char>* copyForSucc = p;
		int first = 0, last = 0;
		//分别记录插入点的N个前驱和N个后继中相同的个数
		while (true)
		{
			if (copyForPred->pred != NULL && copyForPred->Data == copyForPred->pred->Data)
			{
				copyForPred = copyForPred->pred; first++;
			}
			if (copyForSucc->succ != NULL && copyForSucc->Data == copyForSucc->succ->Data)
			{
				copyForSucc = copyForSucc->succ; last++;
			}
		}
		//如果序列满足3个以上的珠子相同
		if (last + first  >= 2)
		{
			list->remove(copyForPred, copyForPred, last + first + 1);
		}
	}
}

void RePlay(ListNode<char> *po, long A, char B)
{
	ListNode<char> *p = list->find(A);//找到插入位置
	p = list->insertAsPred(p, B);//作为前驱插入
    isClear(p);//在每次插入后判断是否需要消除
	
}
int main()
{
	string seq;
	int n;
	int *A; char *B;
	ListNode<char> *posi = new ListNode<char>;
	getline(cin, seq);//输入字符串
	size_t len = seq.size();
	for (int i = 0; i < len; i++)
		posi = list->insertAsSucc(list->headerNode(), seq[i]);//一次插入后续节点值
	scanf("%ld", &n);
	A = new int[n];B = new char[n];
	for (int i = 0; i < n; i++)
		scanf("%ld %c", &A[i], &B[i]);
	for (int i = 0; i < n; i++)
		RePlay(posi, A[i], B[i]);
	return 0;
}
