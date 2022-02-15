#include <iostream>
using namespace std;

class Calculator
{
private:
	int addCnt;
	int minCnt;
	int mulCnt;
	int divCnt;
public:
	void Init();
	void ShowOpCount();
	double Add(double val1, double val2);
	double Min(double val1, double val2);
	double Mul(double val1, double val2);
	double Div(double val1, double val2);
};

void Calculator::Init()
{
	addCnt = 0;
	minCnt = 0;
	mulCnt = 0;
	divCnt = 0;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << addCnt << " »¬¼À: " << minCnt << " °ö¼À: " << mulCnt << " ³ª´°¼À: " << divCnt << endl;
}

double Calculator::Add(double val1, double val2)
{
	addCnt++;
	return val1 + val2;
}

double Calculator::Min(double val1, double val2)
{
	mulCnt++;
	return val1 - val2;
}

double Calculator::Mul(double val1, double val2)
{
	addCnt++;
	return val1 * val2;
}

double Calculator::Div(double val1, double val2)
{
	divCnt++;
	return val1 / val2;
}

int main()
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}