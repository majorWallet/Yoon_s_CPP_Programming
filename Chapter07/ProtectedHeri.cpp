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
	//cout << drv.num3 << endl; // 17���� protected ��ɾ ���ؼ� ������� num3�� ���� ������ protected�� �����. ����, main()���� drv.num3�� ������ �� ����.
	return 0;
}