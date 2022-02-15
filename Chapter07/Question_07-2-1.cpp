#include <iostream>
using namespace std;

class Square
{
private:
	int side;
public:
	Square(int n) : side(n)
	{ }
	int getSide()
	{
		return side;
	}
	void ShowAreaInfo()
	{
		cout << "면적: " << side * side << endl;
	}
};

class Rectangle : public Square
{
private:
	int side2;
public:
	Rectangle(int n1, int n2) : Square(n1), side2(n2)
	{ }
	void ShowAreaInfo()
	{
		cout << "면적: " << getSide() * side2 << endl;
	}
};

int main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}