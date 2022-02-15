#include "CommonDecl.h"
#include "Account.h"
#include "AccountHandler.h"

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