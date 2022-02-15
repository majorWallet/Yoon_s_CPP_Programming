#ifndef __BOUND_CHK_ARR_H__
#define __BOUND_CHK_ARR_H__

#include <iostream>
#include <cstdlib>
#include "PointTemplate.h"
using namespace std;

template <typename T>
class BoundChkArr
{
private:
	T* arr;
	int arrlen;
	BoundChkArr(const BoundChkArr& arr) { }
	BoundChkArr& operator=(const BoundChkArr& arr) { }
public:
	BoundChkArr(int len);
	T& operator[](int idx);
	T& operator[](int idx) const;
	int GetArrLen() const;
	~BoundChkArr();
};

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

#endif