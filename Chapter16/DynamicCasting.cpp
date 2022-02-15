#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) :fuelGauge(fuel)
	{ }
	void ShowCarState() { cout << "잔여 연료량: " << fuelGauge << endl; }
};

class Truck : public Car
{
private:
	int freightWeight;
public:
	Truck(int fuel, int weight)
		:Car(fuel), freightWeight(weight)
	{ }
	void ShowTruckState()
	{
		ShowCarState();
		cout << "화물의 무게: " << freightWeight << endl;
	}
};

int main()
{
	/*
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);  //Compile Error!
	ptruck1->ShowTruckState();
	cout << endl;
	*/

	/*
	Car* pcar2 = new Car(120);
	Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);  //Compile Error!
	ptruck2->ShowTruckState();
	cout << endl;
	*/

	Truck* pcar3 = new Truck(120, 80);
	Car* ptruck3 = dynamic_cast<Car*>(pcar3);
	ptruck3->ShowCarState();
	cout << endl;

	return 0;
}