#include <iostream>
using namespace std;

namespace Hybrid
{
	void Hybfunc()
	{
		cout << "So simple function!" << endl;
		cout << "In namespace Hybrid!" << endl;
	}
}

int main()
{
	using Hybrid::Hybfunc;
	Hybfunc();
	return 0;
}