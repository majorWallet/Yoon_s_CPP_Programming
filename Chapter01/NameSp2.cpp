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
	cout << "BestCom이 정의한 함수" << endl;
}

void ProgComImpl::SimpleFunc()
{
	cout << "ProgCom이 정의한 함수" << endl;
}