#include <iostream>
#include <vector>
#include "Account.h"
extern int accCnt;

static int getMoney()
{
	int money;
	cout << "금액: ";
	cin >> money;
	if (money >= 0)
		return money;
	else
	{
		cout << money << "는 입출금할 수 없는 금액입니다." << endl;
		return 0;
	}
}

static int searchIdx(const vector<Account*>& ptrVec)
{
	char inputID[15];
	cout << "계좌ID: ";
	cin >> inputID;
	for (int i = 0; i < accCnt; i++)
	{
		if (!strcmp(ptrVec[i]->getID(), inputID))
		{
			return i;
		}
	}
	cout << "입력하신 계좌번호를 찾을 수 없습니다." << endl;
	return -1;
}

void depositMoney(const vector<Account*>& ptrVec)
{
	cout << "\n[입금]" << endl;
	int idx = searchIdx(ptrVec);
	int money;
	if (idx > -1)
	{
		money = getMoney();
		(*ptrVec[idx]).deposit(money);
		cout << "입금완료" << endl;
	}
	else
		NULL;
}

void withdrawMoney(const vector<Account*>& ptrVec)
{
	cout << "\n[출금]" << endl;
	int idx = searchIdx(ptrVec);
	int money;
	if (idx > -1)
	{
		if ((money = getMoney()) <= (*ptrVec[idx]).getMoney())
		{
			(*ptrVec[idx]).withdraw(money);
			cout << "출금완료" << endl;
		}
		else
			cout << "잔액부족" << endl;
	}
	else
		NULL;
}