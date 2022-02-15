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
	Book& operator=(Book& ref)
	{
		this->title = new char[strlen(ref.title) + 1];
		strcpy(this->title, ref.title);
		this->isbn = new char[strlen(ref.isbn) + 1];
		strcpy(this->isbn, ref.isbn);
		price = ref.price;
		return *this;
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
	EBook& operator=(EBook& ref)
	{
		ref.operator=(ref);
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
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

	char cn[50] = "?";
	char ci[50] = "?";
	int cp = 0;

	Book book(name1, isbn1, price1);
	EBook ebook(name2, isbn2, price2, drmk2);

	Book copyBook(cn, ci, cp);
	EBook copyEBook = ebook;

	copyBook = book;

	book.ShowBookInfo();
	cout << endl;
	ebook.ShowEBookInfo();

	cout << endl;

	copyBook.ShowBookInfo();
	cout << endl;
	copyEBook.ShowEBookInfo();
	return 0;
}