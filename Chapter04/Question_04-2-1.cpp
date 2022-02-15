#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Ring
{
private:
	Point pos1;
	int rad1 = 0;
	Point pos2;
	int rad2 = 0;
public:
	void Init(int xp1, int yp1, int r1, int xp2, int yp2, int r2)
	{
		pos1.Init(xp1, yp1);
		rad1 = r1;
		pos2.Init(xp2, yp2);
		rad2 = r2;
	}
	bool chkRad() const
	{
		if (rad1 < rad2)
			return true;
		else
			return false;
	}
	void ShowRingInfo() const
	{
		if (chkRad())
		{
			cout << "Inner Circle Info..." << endl;
			cout << "radius: " << rad1 << endl;
			pos1.ShowPointInfo();
			cout << "Outer Circle Info..." << endl;
			cout << "radius: " << rad2 << endl;
			pos2.ShowPointInfo();
		}
		else
			cout << "Outer Circle radius가 Inner Circle radius보다 커야합니다." << endl;
	}
};

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}