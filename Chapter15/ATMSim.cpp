#include <iostream>
#include <string>
using namespace std;

class DepositException
{
private:
	int reqDep;
public:
	DepositException(int money) : reqDep(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: " << reqDep << "는 입금불가]" << endl;
	}
};

class WithdrawException
{
private:
	int balance;
public:
	WithdrawException(int money) : balance(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: 잔액 " << balance << ", 잔액부족]" << endl;
	}
};

class Account
{
private:
	string accNum;
	int balance;
public:
	Account(string acc, int money) : accNum(acc), balance(money)
	{ }
	void Deposit(int money) throw (DepositException)
	{
		if (money < 0)
			throw DepositException(money);
		balance += money;
	}
	void Withdraw(int money) throw (WithdrawException)
	{
		if (money > balance)
			throw WithdrawException(money);
		balance -= money;
	}
	void ShowMyMoney()
	{
		cout << "잔고: " << balance << endl << endl;
	}
};

int main()
{
	Account acc("56789-827120", 5000);

	try
	{
		acc.Deposit(2000);
		acc.Deposit(-300);
	}
	catch (DepositException & expn)
	{
		expn.ShowExceptionReason();
	}
	acc.ShowMyMoney();

	try
	{
		acc.Withdraw(2000);
		acc.Withdraw(5500);
	}
	catch (WithdrawException & expn)
	{
		expn.ShowExceptionReason();
	}
	acc.ShowMyMoney();
	return 0;
}