#include <iostream>
using namespace std;

namespace BestComImpl
{
	void SimpleFunc()
	{
		cout << "BestCom�� ������ �Լ�" << endl;
	}
}

namespace ProgComImpl
{
	void SimpleFunc()
	{
		cout << "ProgCom�� ������ �Լ�" << endl;
	}
}

int main()
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}