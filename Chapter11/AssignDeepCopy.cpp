#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person& operator=(Person& copy)
	{
		age = copy.age;
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy(name, copy.name);
		return *this;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main()
{
	char name1[50] = "Lee dong woo";
	char name2[50] = "Yoon ji yul";
	Person man1(name1, 29);
	Person man2(name2, 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}