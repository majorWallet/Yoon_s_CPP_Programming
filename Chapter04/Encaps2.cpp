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

class CONTAC600
{
private:
	SinivelCap sin;
	SneezeCap snz;
	SnuffleCap snu;

public:
	void Take() const
	{
		sin.Take();
		snz.Take();
		snu.Take();
	}
};

class ColdPatient
{
public:
	void TakeCONTAC600(const CONTAC600& cap) const { cap.Take(); }
};

int main()
{
	CONTAC600 contac;
	ColdPatient p1;
	p1.TakeCONTAC600(contac);
	return 0;
}