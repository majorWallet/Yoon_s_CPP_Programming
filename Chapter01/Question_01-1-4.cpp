#include <iostream>
using namespace std;

int main()
{
	int sellPrice = 0;
	while (1)
	{
		cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		cin >> sellPrice;
		if (sellPrice == -1)
		{
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
		else
			cout << "�̹� �� �޿�: " << (int)(50 + sellPrice * 0.12) << endl;
	}
	return 0;
}