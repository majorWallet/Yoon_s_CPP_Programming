#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "CommonDecl.h"
#include "Account.h"
#include "NormalAccount.h"

class HgihCreditAccount : public NormalAccount
{
private:
	int creditRank;
public:
	HgihCreditAccount(string tempID, string tempName, int tempMoney, double tempRate, int tempRank)
		: NormalAccount(tempID, tempName, tempMoney, tempRate), creditRank(tempRank)
	{ }
	void deposit(int depositMoney)
	{
		NormalAccount::deposit(depositMoney);
		if (creditRank == 1)
			Account::deposit((int)((double)getMoney() * 0.07));
		else if (creditRank == 2)
			Account::deposit((int)((double)getMoney() * 0.04));
		else if (creditRank == 3)
			Account::deposit((int)((double)getMoney() * 0.02));
	}
};

#endif