#include <iostream>
using namespace std;

inline int SQUARE(int x)
{
	return x * x;
}

int main()
{
	cout << SQUARE(5) << endl;
	cout << SQUARE(12) << endl;
	return 0;
}