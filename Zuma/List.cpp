#include <iostream>
using namespace std;
#include "list.h"
#include "stdio.h"
void List::init()
{
	header = new ListNode; //创建头哨兵节点
	trailer = new ListNode; //创建尾哨兵节点
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	header->Data = -1;
	trailer->Data = -1;
	_size = 0; //记录规模
}
