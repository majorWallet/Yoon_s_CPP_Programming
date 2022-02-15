#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "CommonDecl.h"

class Account
{
private:
	char* ID;
	char* name;
	int money;
public:
	Account(char* tempID, char* tempName, int tempMoney)
		:money(tempMoney)
	{
		ID = new char[strlen(tempID) + 1];
		strcpy(ID, tempID);
		name = new char[strlen(tempName) + 1];
		strcpy(name, tempName);
	}
	Account(Account& copy)
		:money(copy.money)
	{
		ID = new char[strlen(copy.ID) + 1];
		strcpy(ID, copy.ID);
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	Account& operator=(Account& copy)
	{
		ID = new char[strlen(copy.ID) + 1];
		strcpy(ID, copy.ID);
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		money = copy.money;
	}
	char* getID() const
	{
		return ID;
	}
	int getMoney() const
	{
		return money;
	}
	virtual void deposit(int depositMoney)
	{
		money += depositMoney;
	}
	void withdraw(int withdrawMoney)
	{
		money -= withdrawMoney;
	}
	void printAcc() const
	{
		cout << "계좌 ID: " << ID << endl;
		cout << "이 름: " << name << endl;
		cout << "예금액: " << money << endl;
	}
	~Account()
	{
		delete[] ID;
		delete[] name;
	}
};

#endif