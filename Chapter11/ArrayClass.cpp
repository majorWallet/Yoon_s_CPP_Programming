#include <iostream>
#include <cstdlib>
using namespace std;

class BoundChekIntArray
{
private:
	int* arr;
	int arrlen;
	BoundChekIntArray(const BoundChekIntArray& arr) { }
	BoundChekIntArray& operator=(const BoundChekIntArray& arr) { }
public:
	BoundChekIntArray(int len) : arrlen(len)
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
	~BoundChekIntArray()
	{
		delete[] arr;
	}
};

int main()
{
	BoundChekIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	for (int i = 0; i < 6; i++)
		cout << arr[i] << endl;
	return 0;
}