#include <iostream>
using namespace std;

int boxVolume();
int boxVolume(int length);
int boxVolume(int length, int width);
int boxVolume(int length, int width, int height);

int main()
{
	cout << "[3, 3, 3] : " << boxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << boxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << boxVolume(7) << endl;
	cout << "[D, D, D] : " << boxVolume() << endl;
	return 0;
}


int boxVolume()
{
	return 1;
}

int boxVolume(int length)
{
	return length * 1;
}

int boxVolume(int length, int width)
{
	return length * width * 1;
}

int boxVolume(int length, int width, int height)
{
	return length * width * height;
}