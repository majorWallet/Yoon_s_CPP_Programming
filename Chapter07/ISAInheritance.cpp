#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
	char owner[50];
public:
	Computer(char* name)
	{
		strcpy(owner, name);
	}
	void Calculate()
	{
		cout << "��û ������ ����մϴ�." << endl;
	}
};

class NotebookComp : public Computer
{
private:
	int Battery;
public:
	NotebookComp(char* name, int initChag)
		:Computer(name), Battery(initChag)
	{ }
	void Charging() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp
{
private:
	char regstPenModel[50];
public:
	TabletNotebook(char* name, int initChag, char* pen)
		:NotebookComp(name, initChag)
	{
		strcpy(regstPenModel, pen);
	}
	void write(char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
};

int main()
{
	char name1[50] = "�̼���";
	char name2[50] = "������";
	char penModel[50] = "ISE-241-242";
	NotebookComp(name1, 5).MovingCal();
	TabletNotebook(name2, 5, penModel).write(penModel);
	return 0;
}