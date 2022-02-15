#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum Rank {CLERK, SENIOR, ASSIST, MANAGER};
}

class NameCard
{
private:
	char* staffName;
	char* companyName;
	char* tel;
	int rank;
public:
	NameCard(char* sn, char* cn, char* t, int r)  /*
		:staffName(sn), companyName(cn), tel(t), rank(r)  //In case of charater pointer, after saves main() local variable address in parameter, saves it member variable  */
	{
		staffName = new char[strlen(sn) + 1];
		companyName = new char[strlen(cn) + 1];
		tel = new char[strlen(t) + 1];
		strcpy(staffName, sn);
		strcpy(companyName, cn);
		strcpy(tel, t);
		rank = r;
	}
	void ShowNameCardInfo() const
	{
		cout << "이름: " << staffName << endl;
		cout << "회사: " << companyName << endl;
		cout << "전화번호: " << tel << endl;
		if (rank == 0)
			cout << "직급: 사원" << endl;
		else if (rank == 1)
			cout << "직급: 주임" << endl;
		else if (rank == 2)
			cout << "직급: 대리" << endl;
		else if (rank == 3)
			cout << "직급: 과장" << endl;
	}
	~NameCard()
	{
		delete[] staffName;
		delete[] companyName;
		delete[] tel;
	}
};

int main()
{
	char staffNameArr[3][5] = {"Lee", "Hong", "Kim"};
	char companyNameArr[3][20] = { "ABCEng", "OrangeEng", "SoGoodcomp" };
	char telArr[3][14] = { "010-1111-2222", "010-3333-4444", "010-5555-6666" };
	NameCard manClerk(staffNameArr[0], companyNameArr[0], telArr[0], COMP_POS::CLERK);
	NameCard manSenior(staffNameArr[1], companyNameArr[1], telArr[1], COMP_POS::SENIOR);
	NameCard manAssist(staffNameArr[2], companyNameArr[2], telArr[2], COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}