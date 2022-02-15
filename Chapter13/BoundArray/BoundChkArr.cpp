#include <iostream>
#include "BoundChkArr.h"
#include "PointTemplate.h"
#include "PointTemplate.cpp"
using namespace std;

template <typename T>
BoundChkArr<T>::BoundChkArr(int len) : arrlen(len)
{
	arr = new T[len];
}

template <typename T>
T& BoundChkArr<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(100);
	}
	else
		return arr[idx];
}

template <typename T>
T& BoundChkArr<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(100);
	}
	else
		return arr[idx];
}

template <typename T>
int BoundChkArr<T>::GetArrLen() const
{
	return arrlen;
}

template <typename T>
BoundChkArr<T>::~BoundChkArr()
{
	delete[] arr;
}