#include <vector>
#include "Account.h"
using namespace std;
extern int accCnt;

static bool chkID(Account*& ptr, const vector<Account*>& ptrVec)
{
	char* name = ptr->getID();
	for (int i = 0; i < accCnt; i++)
		if (!strcmp(ptrVec[i]->getID(), name))
		{
			cout << "������ ID�� �ߺ��˴ϴ�." << endl;
			return false;
		}
	for (int i = 0; i < strlen(name); i++)
		if (!(name[i] >= '0' && name[i] <= '9'))
		{
			cout << "���ڸ� �Է��Ͻÿ�." << endl;
			return false;
		}
	return true;
}

void makeAcc(Account*& ptr, vector<Account*>& ptrVec)
{
	cout << "\n[���°���]" << endl;
	ptr = new Account;
	if (chkID(ptr, ptrVec))
	{
		ptrVec.push_back(ptr);
		accCnt++;
		cout << "���°��� �Ϸ�" << endl;
	}
	else
		delete ptr;
}