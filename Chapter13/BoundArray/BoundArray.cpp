#include <iostream>
#include <cstdlib>
#include "BoundChkArr.h"
#include "PointTemplate.h"
using namespace std;

template <typename T>
void ShowAllData(const BoundChkArr<T>& ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
		ref[idx].ShowPosition();
}

int main()
{
	BoundChkArr<Point<double>> arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = Point<double>(1.1 * (i+1), 2.2 * (i+1));
	}
	ShowAllData(arr);
	return 0;
}