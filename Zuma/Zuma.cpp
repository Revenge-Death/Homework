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
		//�ֱ��¼������N��ǰ����N���������ͬ�ĸ���
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
		//�����������3�����ϵ�������ͬ
		if (last + first  >= 2)
		{
			list->remove(copyForPred, copyForPred, last + first + 1);
		}
	}
}

void RePlay(ListNode<char> *po, long A, char B)
{
	ListNode<char> *p = list->find(A);//�ҵ�����λ��
	p = list->insertAsPred(p, B);//��Ϊǰ������
    isClear(p);//��ÿ�β�����ж��Ƿ���Ҫ����
	
}
int main()
{
	string seq;
	int n;
	int *A; char *B;
	ListNode<char> *posi = new ListNode<char>;
	getline(cin, seq);//�����ַ���
	size_t len = seq.size();
	for (int i = 0; i < len; i++)
		posi = list->insertAsSucc(list->headerNode(), seq[i]);//һ�β�������ڵ�ֵ
	scanf("%ld", &n);
	A = new int[n];B = new char[n];
	for (int i = 0; i < n; i++)
		scanf("%ld %c", &A[i], &B[i]);
	for (int i = 0; i < n; i++)
		RePlay(posi, A[i], B[i]);
	return 0;
}
