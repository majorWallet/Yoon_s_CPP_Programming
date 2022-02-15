#include <iostream>
using namespace std;

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	Base() : num1(1), num2(2), num3(3)
	{ }
};

class Derived : protected Base { };

int main()
{
	Derived drv;
	//cout << drv.num3 << endl; // 17행의 protected 명령어에 의해서 멤버변수 num3의 은닉 범위가 protected로 변경됨. 따라서, main()에서 drv.num3에 접근할 수 없음.
	return 0;
}