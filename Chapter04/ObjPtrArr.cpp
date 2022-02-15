#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* myName, int myAge)
		:name(myName), age(myAge)
	{ }
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", " << "나이: " << age << endl;
	}
	~Person()
	{
		cout << "called destrucotr!" << endl;
	}
};

int main()
{
	Person* perArr[3];
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
		perArr[i] = new Person(nameStr, age);
	}
	for (int i = 0; i < 3; i++)
		perArr[i]->ShowPersonInfo();
	delete perArr[0];
	delete perArr[1];
	delete perArr[2];
	return 0;
}