#include "CommonDecl.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountHandler.h"

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
		cout << "����: ";
		cin >> item;
		if (item == '1' || item == '2' || item == '3' || item == '4' || item == '5')
			return item;
		else
			cout << "Enter only right number" << endl;
	}
}

bool chkID(Account*& ptr, const vector<Account*>& ptrVec, const int& accCnt)
{
	char* name = ptr->getID();
	for (int i = 0; i < accCnt; i++)
		if (!strcmp(ptrVec[i]->getID(), name))
		{
			cout << "������ ID�� �ߺ��˴ϴ�." << endl;
			return false;
		}
	for (int i = 0; i < (int)strlen(name); i++)
		if (!(name[i] >= '0' && name[i] <= '9'))
		{
			cout << "���ڸ� �Է��Ͻÿ�." << endl;
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
		char tempID[15];
		char tempName[15];
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
		char tempID[15];
		char tempName[15];
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
	if (money >= 0)
		return money;
	else
	{
		cout << money << "�� ������� �� ���� �ݾ��Դϴ�." << endl;
		return 0;
	}
}

int searchIdx(const vector<Account*>& ptrVec, const int& accCnt)
{
	char inputID[15];
	cout << "����ID: ";
	cin >> inputID;
	for (int i = 0; i < accCnt; i++)
	{
		if (!strcmp(ptrVec[i]->getID(), inputID))
		{
			return i;
		}
	}
	cout << "�Է��Ͻ� ���¹�ȣ�� ã�� �� �����ϴ�." << endl;
	return -1;
}

void AccountHandler::depositMoney() const
{
	cout << "\n[�Ա�]" << endl;
	int idx = searchIdx(accountPtrVec, AccountHandler::accCnt);
	int money;
	if (idx > -1)
	{
		money = getMoney();
		accountPtrVec[idx]->deposit(money);
		cout << "�ԱݿϷ�" << endl;
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
		if ((money = getMoney()) <= accountPtrVec[idx]->getMoney())
		{
			accountPtrVec[idx]->withdraw(money);
			cout << "��ݿϷ�" << endl;
		}
		else
			cout << "�ܾ׺���" << endl;
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