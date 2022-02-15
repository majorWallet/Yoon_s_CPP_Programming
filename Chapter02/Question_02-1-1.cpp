#include <iostream>
using namespace std;

void plusOne(int& ref)
{
	ref++;
}

void reverseSign(int& ref)
{
	ref = -ref;
}

int main()
{
	int num = 10;
	plusOne(num);
	cout << num << endl;
	reverseSign(num);
	cout << num << endl;
	return 0;
}