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
			cout << "기존의 ID와 중복됩니다." << endl;
			return false;
		}
	for (int i = 0; i < strlen(name); i++)
		if (!(name[i] >= '0' && name[i] <= '9'))
		{
			cout << "숫자만 입력하시오." << endl;
			return false;
		}
	return true;
}

void makeAcc(Account*& ptr, vector<Account*>& ptrVec)
{
	cout << "\n[계좌개설]" << endl;
	ptr = new Account;
	if (chkID(ptr, ptrVec))
	{
		ptrVec.push_back(ptr);
		accCnt++;
		cout << "계좌개설 완료" << endl;
	}
	else
		delete ptr;
}