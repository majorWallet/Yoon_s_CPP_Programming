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
		name = myName;  //'parameter myName'에 'main() function local variable name1'의 address를 저장한 후, 이를 'Person member variable name'에 저장
		                //char* myName = &name1[0]; char* name = &myName[0];
		/*
		int len = strlen(myName) + 1;
		name = new char[len];  //Heap meomory area에 len만큼의 dynamic array를 allocate, character pointer 'name' saves address allocated in Heap memory area
		strcpy(name, myName);  //선언된 dynamic array 'name'에 parameter myName에 저장된 문자열(parameter myName은 main()function's local variable name1, name2의 address를 저장)을 복사
		*/
		age = myAge;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
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