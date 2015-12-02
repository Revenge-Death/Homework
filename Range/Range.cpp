#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "stdio.h"
#include"vector.h"

Vector<int> * vector = new Vector<int>();
void QueryRange(int first, int last, int*A, int n)
{
	int count = 0;
	int start, end;
	start = vector->BinarySearch(A, first, 0, n);
	end = vector->BinarySearch(A, last, 0, n);
	if (start != -1)
	{
		if (first == A[start])//判断端点
			start -= 1;
	}
	printf("%d\n", end - start);
}

int main()
{
	int m, n;
	int * A, *B;//C++中的二维数组相关学习
	int first, last;
	scanf("%d%d", &n, &m);
	A = new  int[n];
	B = new int[m * 2];
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int j = 0; j < m; j++)
	{
		scanf("%d%d", &first, &last);
		B[2 * j] = first;
		B[2 * j + 1] = last;
	}
	vector->merge(A, 0, n);//归并排序
	for (int j = 0; j < m; j++)
		QueryRange(B[2 * j], B[2 * j + 1], A, n);
	return 0;
}