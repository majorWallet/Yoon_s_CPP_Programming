#include <iostream>
using namespace std;

namespace BestComImpl
{
	void SimpleFunc();
}

namespace BestComImpl
{
	void SoPretty();
}

namespace ProgComImpl
{
	void SimpleFunc();
}

int main()
{
	BestComImpl::SimpleFunc();
	return 0;
}

void BestComImpl::SimpleFunc()
{
	cout << "BestCom�� ������ �Լ�" << endl;
	SoPretty();
	ProgComImpl::SimpleFunc();
}

void BestComImpl::SoPretty()
{
	cout << "So Pretty" << endl;
}

void ProgComImpl::SimpleFunc()
{
	cout << "ProgCom�� ������ �Լ�" << endl;
}