#include <iostream>
using namespace std;

int main()
{
	int temp = 0;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "��° ���� �Է�: ";
		cin >> temp;
		sum += temp;
	}
	cout << "�հ�: " << sum << endl;
	return 0;
}