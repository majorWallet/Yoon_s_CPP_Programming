#include <iostream>
#include "Account.h"
#include "AccountHandler.h"
using namespace std;

enum { MAKE = '1', DEPOSIT = '2', WITHDRAW = '3', INQUIRE = '4', EXIT = '5' };

int main()
{
	char item;
	bool shutdown = true;
	AccountHandler handler;
	while (shutdown)
	{
		item = handler.getItem();
		switch (item)
		{
		case MAKE:
			handler.makeAcc();
			break;
		case DEPOSIT:
			handler.depositMoney();
			break;
		case WITHDRAW:
			handler.withdrawMoney();
			break;
		case INQUIRE:
			handler.inquire();
			break;
		case EXIT:
			shutdown = handler.exit();
			break;
		}
	}
}