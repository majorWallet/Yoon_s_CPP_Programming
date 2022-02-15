#include <iostream>
using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(char* name, int age) : age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	~MyFriendInfo()
	{
		delete this->name;
	}
	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(char* name, int age, char* addr, char* phone) : MyFriendInfo(name, age)
	{
		this->addr = new char[strlen(addr) + 1];
		this->phone = new char[strlen(phone) + 1];
		strcpy(this->addr, addr);
		strcpy(this->phone, phone);
	}
	~MyFriendDetailInfo()
	{
		delete this->addr;
		delete this->phone;
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;
	}
};

int main()
{
	char strArr[3][20] = { "AAA", "000-000", "010-1234-5678" };
	MyFriendDetailInfo(strArr[0], 21, strArr[1], strArr[2]).ShowMyFriendDetailInfo();
	return 0;
}