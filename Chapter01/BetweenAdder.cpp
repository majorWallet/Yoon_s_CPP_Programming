#include <iostream>
using namespace std;

int main()
{
	int val1, val2;
	int result = 0;
	cout << "두 개의 숫자입력: ";
	cin >> val1 >> val2;

	if (val1 < val2)
		for (int i = val1 + 1; i < val2; i++)
			result += i;
	else
		for (int i = val2 + 1; i < val1; i++)
			result += i;

	cout << "두 수 사이의 합: " << result << endl;
	return 0;
}