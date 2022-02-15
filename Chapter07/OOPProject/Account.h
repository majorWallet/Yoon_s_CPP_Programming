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
	Account(Account& copy)
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
	void deposit(int depositMoney)
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

class NormalAccount : Account
{
private:
	double interestRate;
public:
	NormalAccount() : Account
	{
		cout << "이자율 (%): ";
		cin >> interestRate;
		interestRate /= 100;
	}
	void deposit(int depositMoney)
	{
		Account::deposit(depositMoney);
		Account::deposit((int)((double)(getMoney() * interestRate));
	}
};

class HgihCreditAccount : NormalAccount
{
private:
	int creditRank;
public:
	HgihCreditAccount() : NormalAccount
	{
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> creditRank;
	}
	void deposit(int depositMoney)
	{
		NormalAccount::deposit(depositMoney);
		if(creditRank == 1)
			NormalAccount::deposit(((int)(double)(getMoney() * 0.07));
		else if (creditRank == 2)
			NormalAccount::deposit(((int)(double)(getMoney() * 0.04));
		else if (creditRank == 3)
			NormalAccount::deposit(((int)(double)(getMoney() * 0.02));
	}
};

#endif