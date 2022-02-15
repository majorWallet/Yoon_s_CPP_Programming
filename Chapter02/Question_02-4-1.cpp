#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str1[100];
	char str2[50];
	cin >> str1;
	strcpy(str2, str1);
	if (!strcmp(str1, str2))
		strcat(str1, str2);
	else
		cout << "Sorry, Program Error!	:(";

	for (int i = 0; i < strlen(str1); i++)
Question_02-4-2		cout << str1[i];
	cout << endl;
	
	return 0;
}