#include <iostream>
using namespace std;

class Data
{
private:
	int data;
public:
	Data(int num): data(num)
	{ }
	void showData() { cout << "Data: " << data << endl; }
	void Add(int num) { data += num; }
};

int main()
{
	Data obj(15);
	obj.Add(17);
	obj.showData();
	return 0;
}