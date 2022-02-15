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
	{
		name = myName;  //'parameter myName'�� 'main() function local variable name1'�� address�� ������ ��, �̸� 'Person member variable name'�� ����
		                //char* myName = &name1[0]; char* name = &myName[0];
		/*
		int len = strlen(myName) + 1;
		name = new char[len];  //Heap meomory area�� len��ŭ�� dynamic array�� allocate, character pointer 'name' saves address allocated in Heap memory area
		strcpy(name, myName);  //����� dynamic array 'name'�� parameter myName�� ����� ���ڿ�(parameter myName�� main()function's local variable name1, name2�� address�� ����)�� ����
		*/
		age = myAge;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()
	{
		//delete[]name;
		cout << "called destrucotr!" << endl;
	}
};

int main()
{
	char name1[50] = "Lee dong woo";
	char name2[50] = "Jang dong gun";
	Person man1(name1, 29);
	Person man2(name2, 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}