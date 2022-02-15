#include "CommonDecl.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountHandler.h"
#include "AccException.h"

void flushInputBuf()
{
	while (getchar() != '\n');
}

void menu()
{
	cout << "\n-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

char AccountHandler::getItem() const
{
	menu();
	char item;
	while (true)
	{
		try
		{
			cout << "선택: ";
			cin >> item;
			if (!(item == '1' || item == '2' || item == '3' || item == '4' || item == '5'))
			{
				flushInputBuf();
				throw ItemException(item);
			}
			return item;
		}
		catch (Exception &ref)
		{
			ref.ShowExceptionReason();
		}
	}
}

bool chkID(Account*& ptr, const vector<Account*>& ptrVec, const int& accCnt)
{
	string ID = ptr->getID();
	try
	{
		for (int i = 0; i < accCnt; i++)
			if (ptrVec[i]->getID() == ID)
			{
				throw chkIDException(ID);
			}
	}
	catch (Exception& ref)
	{
		ref.ShowExceptionReason();
		return false;
	}
	try
	{
		for (int i = 0; i < ID.length(); i++)
			if (!(ID[i] >= '0' && ID[i] <= '9'))
			{
				flushInputBuf();
				throw ItemException(ID[i]);
			}
	}
	catch (Exception & ref)
	{
		ref.ShowExceptionReason();
		return false;
	}
	return true;
}

void AccountHandler::makeAcc()
{
	char accType = '0';

	cout << "\n[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cin >> accType;

	if (accType == '1')
	{
		string tempID;
		string tempName;
		int tempMoney;
		double interestRate;

		cout << "\n[보통예금계좌 개설]" << endl;
		cout << "계좌 ID: ";
		cin >> tempID;
		cout << "이 름: ";
		cin >> tempName;
		cout << "입금액: ";
		cin >> tempMoney;
		cout << "이자율 (%): ";
		cin >> interestRate;
		interestRate /= 100;

		accountPtr = new NormalAccount(tempID, tempName, tempMoney, interestRate);
		if (chkID(accountPtr, accountPtrVec, AccountHandler::accCnt))
		{
			accountPtrVec.push_back(accountPtr);
			accCnt++;
			cout << "계좌개설 완료" << endl;
		}
		else
			delete accountPtr;
	}

	else if (accType == '2')
	{
		string tempID;
		string tempName;
		int tempMoney;
		double tempRate;
		int tempRank;

		cout << "\n[신용신뢰계좌 개설]" << endl;
		cout << "계좌 ID: ";
		cin >> tempID;
		cout << "이 름: ";
		cin >> tempName;
		cout << "입금액: ";
		cin >> tempMoney;
		cout << "이자율 (%): ";
		cin >> tempRate;
		tempRate /= 100;
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> tempRank;

		accountPtr = new HgihCreditAccount(tempID, tempName, tempMoney, tempRate, tempRank);
		if (chkID(accountPtr, accountPtrVec, AccountHandler::accCnt))
		{
			accountPtrVec.push_back(accountPtr);
			accCnt++;
			cout << "계좌개설 완료" << endl;
		}
		else
			delete accountPtr;
	}
	else
	{
		cout << "알맞은 문자를 입력하시오." << endl;
	}
}

int getMoney()
{
	int money;
	cout << "금액: ";
	cin >> money;
	return money;
	return 0;
}

int searchIdx(const vector<Account*>& ptrVec, const int& accCnt)
{
	string inputID;
	cout << "계좌ID: ";
	cin >> inputID;
	for (int i = 0; i < accCnt; i++)
	{
		if (ptrVec[i]->getID() == inputID)
		{
			return i;
		}
	}
	cout << "The account you entered could not be found" << endl;
	return -1;
}

void AccountHandler::depositMoney() const
{
	cout << "\n[입금]" << endl;
	int idx = searchIdx(accountPtrVec, AccountHandler::accCnt);
	int money;
	if (idx > -1)
	{
		try
		{
			money = getMoney();
			if (money <= 0)
				throw chkMoneyException(money);
			else
			{
				accountPtrVec[idx]->deposit(money);
				cout << "입금완료" << endl;
			}
		}
		catch (Exception & ref)
		{
			ref.ShowExceptionReason();
		}
	}
	else
		NULL;
}

void AccountHandler::withdrawMoney() const
{
	cout << "\n[출금]" << endl;
	int idx = searchIdx(accountPtrVec, AccountHandler::accCnt);
	int money;
	if (idx > -1)
	{
		try
		{
			if ((money = getMoney()) > accountPtrVec[idx]->getMoney())
				throw withdrawException(accountPtrVec[idx]->getMoney());
			else
			{
				accountPtrVec[idx]->withdraw(money);
				try
				{
					if (money <= 0)
						throw chkMoneyException(money);
					else
						cout << "출금완료" << endl;
				}
				catch (Exception & ref)
				{
					ref.ShowExceptionReason();
				}
			}
		}
		catch (Exception & ref)
		{
			ref.ShowExceptionReason();
		}
	}
	else
		NULL;
}

void AccountHandler::inquire() const
{
	for (int i = 0; i < accCnt; i++)
		accountPtrVec[i]->printAcc();
}

bool AccountHandler::exit()
{
	for (int i = 0; i < accCnt; i++)
		delete accountPtrVec[i];
	return false;
}