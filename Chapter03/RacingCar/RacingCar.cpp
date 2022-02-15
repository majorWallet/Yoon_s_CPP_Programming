#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car
{
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;
};

void ShowCarState(const Car& car)
{
	cout << "소유자ID: " << car.gamerID << endl;
	cout << "연료랑: " << car.fuelGauge << "%" << endl;
	cout << "현재속도: " << car.curSpeed << "km/h" << endl << endl;
}

void Accel(Car& car)
{
	if (car.fuelGauge <= 0)
		return;
	else
		car.fuelGauge -= FUEL_STEP;

	if (car.curSpeed + ACC_STEP >= MAX_SPD)
	{
		car.curSpeed = MAX_SPD;
		return;
	}
	else
		car.curSpeed += ACC_STEP;
}

void Break(Car& car)
{
	if (car.curSpeed < BRK_STEP)
	{
		car.curSpeed = 0;
		return;
	}
	else
		car.curSpeed -= BRK_STEP;
}

int main()
{
	Car run99 = { "run99", 100, 0 };
	Accel(run99);
	Accel(run99);
	ShowCarState(run99);
	Break(run99);
	ShowCarState(run99);

	Car speed77 = { "speed77", 100, 0 };
	Accel(speed77);
	Break(speed77);
	ShowCarState(speed77);
	return 0;
}