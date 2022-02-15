#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "CommonDecl.h"
#include "Account.h"

class NormalAccount : public Account
{
private:
	double interestRate;
public:
	NormalAccount(string tempID, string tempName, int tempMoney, double tempRate)
		: Account(tempID, tempName, tempMoney), interestRate(tempRate)
	{ }
	void deposit(int depositMoney)
	{
		Account::deposit(depositMoney);
		Account::deposit((int)((double)getMoney() * interestRate));
	}
};

#endif