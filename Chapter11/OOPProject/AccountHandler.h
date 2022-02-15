#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "CommonDecl.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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

#endif