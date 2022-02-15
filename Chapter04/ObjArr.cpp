#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person()
		:name(NULL), age(0)
	{ }
	void SetPersonInfo(char* myName, int myAge)
	{
		name = myName;
		age = myAge;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", " << "나이: " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destrucotr!" << endl;
	}
};

int main()
{
	Person perArr[3];
	char nameStr[100];
	char* strptr;
	int age;
	int len;
	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> nameStr;
		cout << "나이: ";
		cin >> age;
		len = strlen(nameStr) + 1;
		strptr = new char[len];
		strcpy(strptr, nameStr);
		perArr[i].SetPersonInfo(strptr, age);
	}
	for (int i = 0; i < 3; i++)
		perArr[i].ShowPersonInfo();
	return 0;
}