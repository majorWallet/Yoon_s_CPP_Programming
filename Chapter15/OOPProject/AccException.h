#ifndef __ACC_EXCEPTION_H__
#define __ACC_EXCEPTION_H__
#include "CommonDecl.h"

class Exception
{
public:
	virtual void ShowExceptionReason() = 0;
};

class ItemException : public Exception
{
private:
	char item;
public:
	ItemException(char item) : item(item)
	{ }
	void ShowExceptionReason()
	{
		cout << "'" << item << "'" << " is unavailable character" << endl;
		cout << "Enter only right number" << endl;
	}
};

class chkIDException : public Exception
{
private:
	string ID;
public:
	chkIDException(string ID) : ID(ID)
	{ }
	void ShowExceptionReason()
	{
		cout << "\"" << ID << "\"" << " is duplicated with existing ID" << endl;
		cout << "Enter only IDs do not existing" << endl;
	}
};

class chkMoneyException : public Exception
{
private:
	int money;
public:
	chkMoneyException(int money) : money(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "'" << money << "'" << " is unable to withdrawal" << endl;
		cout << "Enter only right amount" << endl;
	}
};

class withdrawException : public Exception
{
private:
	int balance;
public:
	withdrawException(int balance) : balance(balance)
	{ }
	void ShowExceptionReason()
	{
		cout << "Insufficient balance" << endl;
		cout << "balance: " << balance << endl;
	}
};

#endif