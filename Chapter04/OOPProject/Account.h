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
		cout << "���� ID: ";
		cin >> tempID;
		cout << "�� ��: ";
		cin >> tempName;
		cout << "�Աݾ�: ";
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
		cout << "���� ID: " << ID << endl;
		cout << "�� ��: " << name << endl;
		cout << "�Աݾ�: " << money << endl;
	}
};

#endif