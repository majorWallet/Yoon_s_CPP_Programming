#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point point;
	point.xpos = p1.xpos + p2.xpos;
	point.ypos = p1.ypos + p2.ypos;
	return point;
}

int main()
{
	Point* point = new Point[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "(x, y): ";
		cin >> point[i].xpos >> point[i].ypos;
	}
	cout << "(" << PntAdder(point[0], point[1]).xpos << ", " << PntAdder(point[0], point[1]).ypos << ")" << endl;
	return 0;
}