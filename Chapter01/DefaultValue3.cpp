#include <iostream>
using namespace std;

int boxVolume(int length, int width = 1, int height = 1);

int main()
{
	cout << "[3, 3, 3] : " << boxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << boxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << boxVolume(7) << endl;
	//cout << "[D, D, D] : " << boxVolume() << endl;
	return 0;
}

int boxVolume(int length, int width, int height)
{
	return length * width * height;
}