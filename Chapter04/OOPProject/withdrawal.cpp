#include <iostream>
#include <vector>
#include "Account.h"
extern int accCnt;

static int getMoney()
{
	int money;
	cout << "�ݾ�: ";
	cin >> money;
	if (money >= 0)
		return money;
	else
	{
		cout << money << "�� ������� �� ���� �ݾ��Դϴ�." << endl;
		return 0;
	}
}

static int searchIdx(const vector<Account*>& ptrVec)
{
	char inputID[15];
	cout << "����ID: ";
	cin >> inputID;
	for (int i = 0; i < accCnt; i++)
	{
		if (!strcmp(ptrVec[i]->getID(), inputID))
		{
			return i;
		}
	}
	cout << "�Է��Ͻ� ���¹�ȣ�� ã�� �� �����ϴ�." << endl;
	return -1;
}

void depositMoney(const vector<Account*>& ptrVec)
{
	cout << "\n[�Ա�]" << endl;
	int idx = searchIdx(ptrVec);
	int money;
	if (idx > -1)
	{
		money = getMoney();
		(*ptrVec[idx]).deposit(money);
		cout << "�ԱݿϷ�" << endl;
	}
	else
		NULL;
}

void withdrawMoney(const vector<Account*>& ptrVec)
{
	cout << "\n[���]" << endl;
	int idx = searchIdx(ptrVec);
	int money;
	if (idx > -1)
	{
		if ((money = getMoney()) <= (*ptrVec[idx]).getMoney())
		{
			(*ptrVec[idx]).withdraw(money);
			cout << "��ݿϷ�" << endl;
		}
		else
			cout << "�ܾ׺���" << endl;
	}
	else
		NULL;
}