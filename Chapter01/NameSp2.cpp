#include <iostream>
using namespace std;

namespace BestComImpl
{
	void SimpleFunc();
}

namespace ProgComImpl
{
	void SimpleFunc();
}

int main()
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}

void BestComImpl::SimpleFunc()
{
	cout << "BestCom�� ������ �Լ�" << endl;
}

void ProgComImpl::SimpleFunc()
{
	cout << "ProgCom�� ������ �Լ�" << endl;
}