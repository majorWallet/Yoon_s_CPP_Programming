#include <iostream>
using namespace std;

int main()
{
	int sellPrice = 0;
	while (1)
	{
		cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		cin >> sellPrice;
		if (sellPrice == -1)
		{
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		else
			cout << "이번 달 급여: " << (int)(50 + sellPrice * 0.12) << endl;
	}
	return 0;
}