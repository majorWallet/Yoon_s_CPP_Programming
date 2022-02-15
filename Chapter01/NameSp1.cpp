#include <iostream>
using namespace std;

namespace BestComImpl
{
	void SimpleFunc()
	{
		cout << "BestCom이 정의한 함수" << endl;
	}
}

namespace ProgComImpl
{
	void SimpleFunc()
	{
		cout << "ProgCom이 정의한 함수" << endl;
	}
}

int main()
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}