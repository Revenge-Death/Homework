#include <iostream>
using namespace std;
#include "vector.h"

template<typename T>Rank Vector<T>::BinarySearch(T *A, T const & e, Rank lo, Rank hi)
{
	while (hi > lo)
	{
		int mi = (hi - lo) >> 1;
		e > A[mi] ? lo = mi : hi = mi;
	}
	return --lo;
}

template<typename T>void Vector<T>::merge(T *A, Rank lo, Rank hi)
{
	if ((hi - lo) < 2)
		return;
	merge(A, lo, hi);
}

template<typename T>void Vector<T>::mergeSort(T *A, Rank lo,Rank mi, Rank hi)
{
	int k = 0, q = 0;
	int lb = mi - lo;
	int lc = hi - mi;
	T *B = new int[lb];
	T *C = new int[lc];
	for (int i = 0; i < lb; i++)
		B[i] = A[lo + i];
	for (int j = 0; j < lc; j++)
		C[j] = A[mi + j];
	while (k < lb || q < lc)
	{
		if (k < lb && (q >= lc || B[k] <= C[Q]))
			B[k++] = A[lo++];
		if (q < lc && (b >= lb || C[Q] < B[k] ))
			C[k++] = A[mi++];
	}
}