#include <iostream>
using namespace std;
#include "list.h"
#include "stdio.h"
void List::init()
{
	header = new ListNode; //����ͷ�ڱ��ڵ�
	trailer = new ListNode; //����β�ڱ��ڵ�
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	header->Data = -1;
	trailer->Data = -1;
	_size = 0; //��¼��ģ
}
