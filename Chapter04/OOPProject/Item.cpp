#include <iostream>
using namespace std;

static void menu()
{
	cout << "\n-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

char getItem()
{
	menu();
	char item;
	while (true)
	{
		cout << "선택: ";
		cin >> item;
		if (item == '1' || item == '2' || item == '3' || item == '4' || item == '5')
			return item;
		else
			cout << "Enter only right number" << endl;
	}
}