#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	int age;
	char name[50];
public:
	Person(int myage, char* myname) : age(myage)
	{
		strcpy(name, myname);
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old" << endl;
	}
};

class UnivStudent : public Person
{
private:
	char major[50];
public:
	UnivStudent(char* myname, int myage, char* mymajor)
		:Person(myage, myname)
	{
		strcpy(major, mymajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main()
{
	char name[2][50] = { "Lee", "Yoon" };
	char major[2][50] = { "Computer eng.", "Electronic eng." };
	UnivStudent ustd1 = { name[0], 22, major[0] };
	UnivStudent ustd2 = { name[1], 21, major[1] };
	ustd1.WhoAreYou();
	ustd2.WhoAreYou();
	return 0;
}