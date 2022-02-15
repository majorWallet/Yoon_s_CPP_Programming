#include <iostream>
#include <vector>
#include "Item.h"
#include "Account.h"
#include "makeAcc.h"
#include "withdrawal.h"
using namespace std;

enum { MAKE = '1', DEPOSIT = '2', WITHDRAW = '3', INQUIRE = '4', EXIT = '5' };
int accCnt = 0;

inline void inquire(const vector<Account*>& ptrVec)
{
	for (int i = 0; i < accCnt; i++)
		(*ptrVec[i]).printAcc();
}

inline bool exit(const vector<Account*>& ptrVec)
{
	for (int i = 0; i < accCnt; i++)
		delete ptrVec[i];
	return false;
}

int main()
{
	char item;
	bool shutdown = true;
	Account* accountPtr = NULL;
	vector<Account*> accountPtrVec;
	while (shutdown)
	{
		item = getItem();
		switch (item)
		{
		case MAKE:
			makeAcc(accountPtr, accountPtrVec);
			break;
		case DEPOSIT:
			depositMoney(accountPtrVec);
			break;
		case WITHDRAW:
			withdrawMoney(accountPtrVec);
			break;
		case INQUIRE:
			inquire(accountPtrVec);
			break;
		case EXIT:
			shutdown = exit(accountPtrVec);
			break;
		}
	}
}