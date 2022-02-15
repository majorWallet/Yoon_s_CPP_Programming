#include <iostream>
using namespace std;

void swap(int* val1, int* val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void swap(char* val1, char* val2)
{
	char temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void swap(double* val1, double* val2)
{
	double temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

int main()
{
	int num1 = 10, num2 = 20;
	swap(&num1, &num2);
	cout << num1 << ' ' << num2 << endl;

	char ch1 = 'A', ch2 = 'B';
	swap(&ch1, &ch2);
	cout << ch1 << ' ' << ch2 << endl;

	double db1 = 1.11, db2 = 2.22;
	swap(&db1, &db2);
	cout << db1 << ' ' << db2 << endl;
}