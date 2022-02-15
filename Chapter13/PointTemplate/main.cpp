#include <iostream>
#include "PointTemplate.h"
#include "PointTemplate.cpp"
using namespace std;

int main()
{
	Point<int> pos1(1, 1);
	pos1.ShowPosition();
	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();
	return 0;
}