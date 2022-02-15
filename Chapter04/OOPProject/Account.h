#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <cstring>
#include <iostream>
using namespace std;

class Account
{
private:
	char* ID;
	char* name;
	int money;
public:
	Account()
	{
		char tempID[15];
		char tempName[15];
		int tempMoney;
		cout << "계좌 ID: ";
		cin >> tempID;
		cout << "이 름: ";
		cin >> tempName;
		cout << "입금액: ";
		cin >> tempMoney;
		ID = new char[strlen(tempID) + 1];
		strcpy(ID, tempID);
		name = new char[strlen(tempName) + 1];
		strcpy(name, tempName);
		money = tempMoney;
	}
	char* getID()
	{
		return ID;
	}
	int getMoney()
	{
		return money;
	}
	void deposit(int depositMoney)
	{
		money += depositMoney;
	}
	void withdraw(int withdrawMoney)
	{
		money -= withdrawMoney;
	}
	void printAcc()
	{
		cout << "계좌 ID: " << ID << endl;
		cout << "이 름: " << name << endl;
		cout << "입금액: " << money << endl;
	}
};

#endif