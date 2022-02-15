#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	int age;
	char* name;
public:
	Person(int myage, char* myname)
		: age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	~Person()
	{
		delete name;
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
	char* major;
public:
	UnivStudent(char* myname, int myage, char* mymajor)
		: Person(myage, myname)
	{
		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}
	~UnivStudent()
	{
		delete major;
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
	ustd1.WhoAreYou();
	UnivStudent ustd2 = { name[1], 21, major[1] };
	ustd2.WhoAreYou();
	return 0;
}