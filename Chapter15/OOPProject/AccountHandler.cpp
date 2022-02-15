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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

char AccountHandler::getItem() const
{
	menu();
	char item;
	while (true)
	{
		try
		{
			cout << "����: ";
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

	cout << "\n[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cin >> accType;

	if (accType == '1')
	{
		string tempID;
		string tempName;
		int tempMoney;
		double interestRate;

		cout << "\n[���뿹�ݰ��� ����]" << endl;
		cout << "���� ID: ";
		cin >> tempID;
		cout << "�� ��: ";
		cin >> tempName;
		cout << "�Աݾ�: ";
		cin >> tempMoney;
		cout << "������ (%): ";
		cin >> interestRate;
		interestRate /= 100;

		accountPtr = new NormalAccount(tempID, tempName, tempMoney, interestRate);
		if (chkID(accountPtr, accountPtrVec, AccountHandler::accCnt))
		{
			accountPtrVec.push_back(accountPtr);
			accCnt++;
			cout << "���°��� �Ϸ�" << endl;
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

		cout << "\n[�ſ�ŷڰ��� ����]" << endl;
		cout << "���� ID: ";
		cin >> tempID;
		cout << "�� ��: ";
		cin >> tempName;
		cout << "�Աݾ�: ";
		cin >> tempMoney;
		cout << "������ (%): ";
		cin >> tempRate;
		tempRate /= 100;
		cout << "�ſ���(1toA, 2toB, 3toC): ";
		cin >> tempRank;

		accountPtr = new HgihCreditAccount(tempID, tempName, tempMoney, tempRate, tempRank);
		if (chkID(accountPtr, accountPtrVec, AccountHandler::accCnt))
		{
			accountPtrVec.push_back(accountPtr);
			accCnt++;
			cout << "���°��� �Ϸ�" << endl;
		}
		else
			delete accountPtr;
	}
	else
	{
		cout << "�˸��� ���ڸ� �Է��Ͻÿ�." << endl;
	}
}

int getMoney()
{
	int money;
	cout << "�ݾ�: ";
	cin >> money;
	return money;
	return 0;
}

int searchIdx(const vector<Account*>& ptrVec, const int& accCnt)
{
	string inputID;
	cout << "����ID: ";
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
	cout << "\n[�Ա�]" << endl;
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
				cout << "�ԱݿϷ�" << endl;
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
	cout << "\n[���]" << endl;
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
						cout << "��ݿϷ�" << endl;
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