#include <iostream>
using namespace std;

int main()
{
	int val1;
	cout << "첫 번째 숫자입력: ";
	cin >> val1;

	int val2;
	cout << "두 번째 숫자입력: ";
	cin >> val2;

	int result = val1 + val2;
	cout << "덧셈결과: " << result << endl;
	return 0;
}