#include <iostream>
using namespace std;

namespace Parent
{
	char str[50] = "Parent";
	namespace Sub
	{
		char str[50] = "Sub";
	}
}

int main()
{
	cout << Parent::str << endl;
	cout <<	Parent::Sub::str << endl;
	return 0;
}