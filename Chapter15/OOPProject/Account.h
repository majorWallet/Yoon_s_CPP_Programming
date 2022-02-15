#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "CommonDecl.h"

class Account
{
private:
	string ID;
	string name;
	int money;
public:
	Account(string tempID, string tempName, int tempMoney)
		:ID(tempID), name(tempName), money(tempMoney)
	{ }
	Account(Account& copy)
		:ID(copy.ID), name(copy.name), money(copy.money)
	{ }
	Account& operator=(Account& copy)
	{
		ID = copy.ID;
		name = copy.name;
		money = copy.money;
	}
	string getID() const
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
};

#endif