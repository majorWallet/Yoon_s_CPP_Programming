#include <iostream>
using namespace std;

void MyFunc()
{
	cout << "MyFunc() called" << endl;
}

void MyFunc(char ch)
{
	cout << "MyFunc(char ch) called" << endl;
}

void MyFunc(int a, int b)
{
	cout << "MyFunc(int a, int b) called" << endl;
}

int main()
{
	MyFunc();
	MyFunc('A');
	MyFunc(1, 2);
	return 0;
}