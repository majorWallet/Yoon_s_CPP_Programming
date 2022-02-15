#include <iostream>
using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int gauge)
		:gasolineGauge(gauge)
	{ }
	int GetGasGuage()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gGuage, int eGuage) : Car(gGuage), electricGauge(eGuage)
	{ }
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridHydrogenCar : public HybridCar
{
private:
	int HydrogenGauge;
public:
	HybridHydrogenCar(int gGuage, int eGuage, int hGuage) : HybridCar(gGuage, eGuage), HydrogenGauge(hGuage)
	{ }
	int GetHydroGauge()
	{
		return HydrogenGauge;
	}
	void ShowCurrentGauge()
	{
		cout << "�ܿ� ���ָ�: " << GetGasGuage() << endl;
		cout << "�ܿ� ���ָ�: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ָ�: " << GetHydroGauge() << endl;
	}
};

int main()
{
	HybridHydrogenCar(10, 5, 7).ShowCurrentGauge();
}