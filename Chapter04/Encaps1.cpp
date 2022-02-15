#include <iostream>
using namespace std;

class SinivelCap
{
public:
	void Take() const { cout << "Äà¹°ÀÌ ½Ï~ ³³´Ï´Ù." << endl; }
};

class SneezeCap
{
public:
	void Take() const { cout << "ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù." << endl; }
};

class SnuffleCap
{
public:
	void Take() const { cout << "ÄÚ°¡ »½ ¶Õ¸³´Ï´Ù." << endl; }
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