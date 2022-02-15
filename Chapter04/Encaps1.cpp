#include <iostream>
using namespace std;

class SinivelCap
{
public:
	void Take() const { cout << "�๰�� ��~ ���ϴ�." << endl; }
};

class SneezeCap
{
public:
	void Take() const { cout << "��ä�Ⱑ �ܽ��ϴ�." << endl; }
};

class SnuffleCap
{
public:
	void Take() const { cout << "�ڰ� �� �ո��ϴ�." << endl; }
};

class ColdPatient
{
public:
	void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); }
	void TakeSneezeCap(const SneezeCap& cap) const { cap.Take(); }
	void TakeSnuffleCap(const SnuffleCap& cap) const { cap.Take(); }
};

int main()
{
	SinivelCap cap1;
	SneezeCap cap2;
	SnuffleCap cap3;

	ColdPatient p1;
	p1.TakeSinivelCap(cap1);
	p1.TakeSneezeCap(cap2);
	p1.TakeSnuffleCap(cap3);
	return 0;
}