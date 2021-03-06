#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include <iostream>
#include <cstring>
#include <vector>
#include "Account.h"
using namespace std;

class AccountHandler
{
private:
	Account* accountPtr;
	vector<Account*> accountPtrVec;
	int accCnt;
public:
	AccountHandler() : accountPtr(NULL), accCnt(0)
	{ }
	char getItem() const;
	void makeAcc();
	void depositMoney() const;
	void withdrawMoney() const;
	void inquire() const;
	bool exit();
};

void menu()
{
	cout << "\n-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

char AccountHandler::getItem() const
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

bool chkID(Account*& ptr, const vector<Account*>& ptrVec, const int& accCnt)
{
	char* name = ptr->getID();
	for (int i = 0; i < accCnt; i++)
		if (!strcmp(ptrVec[i]->getID(), name))
		{
			cout << "기존의 ID와 중복됩니다." << endl;
			return false;
		}
	for (int i = 0; i < strlen(name); i++)
		if (!(name[i] >= '0' && name[i] <= '9'))
		{
			cout << "숫자만 입력하시오." << endl;
			return false;
		}
	return true;
}

void AccountHandler::makeAcc()
{
	char accType = '0';
	cout << "\n[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cin >> accType;
	if (accType == '1')
	{
		cout << "\n[보통예금계좌 개설]" << endl;
		accountPtr = new NormalAccount;
		if (chkID(accountPtr, accountPtrVec, AccountHandler::accCnt))
		{
			accountPtrVec.push_back(accountPtr);
			accCnt++;
			cout << "계좌개설 완료" << endl;
		}
		else
			delete accountPtr;
	}
	else if (accType == '2')
	{
		cout << "\n[신용신뢰계좌 개설]" << endl;
		accountPtr = new HgihCreditAccount;
		if (chkID(accountPtr, accountPtrVec, AccountHandler::accCnt))
		{
			accountPtrVec.push_back(accountPtr);
			accCnt++;
			cout << "계좌개설 완료" << endl;
		}
		else
			delete accountPtr;
	}
	else
	{
		cout << "알맞은 문자를 입력하시오." << endl;
	}
}

int getMoney()
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

int searchIdx(const vector<Account*>& ptrVec, const int& accCnt)
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

void AccountHandler::depositMoney() const
{
	cout << "\n[입금]" << endl;
	int idx = searchIdx(accountPtrVec, AccountHandler::accCnt);
	int money;
	if (idx > -1)
	{
		money = getMoney();
		accountPtrVec[idx]->deposit(money);
		cout << "입금완료" << endl;
	}
	else
		NULL;
}

void AccountHandler::withdrawMoney() const
{
	cout << "\n[출금]" << endl;
	int idx = searchIdx(accountPtrVec, AccountHandler::accCnt);
	int money;
	if (idx > -1)
	{
		if ((money = getMoney()) <= accountPtrVec[idx]->getMoney())
		{
			accountPtrVec[idx]->withdraw(money);
			cout << "출금완료" << endl;
		}
		else
			cout << "잔액부족" << endl;
	}
	else
		NULL;
}

void AccountHandler::inquire() const
{
	for (int i = 0; i < accCnt; i++)
		accountPtrVec[i]->printAcc();
}

bool AccountHandler::exit()
{
	for (int i = 0; i < accCnt; i++)
		delete accountPtrVec[i];
	return false;
}

#endif