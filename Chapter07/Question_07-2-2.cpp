#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(char* title, char* isbn, int price) : price(price)
	{
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;
public:
	EBook(char* title, char* isbn, int price, char* drmk) : Book(title, isbn, price)
	{
		DRMKey = new char[strlen(drmk) + 1];
		strcpy(DRMKey, drmk);
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "DRMKey: " << DRMKey << endl;
	}
};

int main()
{
	char name1[50] = "좋은 C++";
	char isbn1[50] = "555-12345-890-0";
	int price1 = 20000;
	char name2[50] = "좋은 C++ ebook";
	char isbn2[50] = "555-12345-890-1";
	int price2 = 10000;
	char drmk2[50] = "fdx9w0i8kiw";
	Book book(name1, isbn1, price1);
	EBook ebook(name2, isbn2, price2, drmk2);
	book.ShowBookInfo();
	cout << endl;
	ebook.ShowEBookInfo();
	return 0;
}