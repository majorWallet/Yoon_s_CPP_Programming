#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) : arr(NULL), arrlen(0) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(100);
		}
		else
			return arr[idx];
	}
	int& operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(100);
		}
		else
			return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
	~BoundCheckIntArray()
	{
		delete[] arr;
	}
};

class BoundCheck2DIntArray
{
private:
	BoundCheckIntArray** arr2D;
	int rowlen;
	int collen;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) : arr2D(NULL), rowlen(0), collen(0) { }
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) { }
public:
	BoundCheck2DIntArray(int col, int row) : collen(col), rowlen(row)
	{
		arr2D = new BoundCheckIntArray* [collen];
		for (int i = 0; i < collen; i++)
		{
			arr2D[i] = new BoundCheckIntArray(rowlen);
		}
	}
	BoundCheckIntArray& operator[](int idx)
	{
		if (idx < 0 || idx >= collen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(100);
		}
		else
			return *arr2D[idx];
	}
	BoundCheckIntArray& operator[](int idx) const
	{
		if (idx < 0 || idx >= collen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(100);
		}
		else
			return *arr2D[idx];
	}
	int GetColLen() const
	{
		return collen;
	}
	int GetRowLen() const
	{
		return rowlen;
	}
	~BoundCheck2DIntArray()
	{
		for(int i = 0; i < collen; i++)
			delete[] arr2D[i];
		delete[] arr2D;
	}
};

void ShowAllData(const BoundCheck2DIntArray& ref)
{
	for (int i = 0; i < ref.GetColLen(); i++)
	{
		for (int j = 0; j < ref.GetRowLen(); j++)
			cout << ' ' << ref[i][j];
		cout << endl;
	}
}

int main()
{
	BoundCheck2DIntArray arr(5, 4);
	for (int i = 0; i < arr.GetColLen(); i++)
		for (int j = 0; j < arr.GetRowLen(); j++)
			arr[i][j] = 1;
	ShowAllData(arr);
	return 0;
}