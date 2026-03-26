#pragma once
#include "Book.h"
#include <vector>
using namespace std;
class Library
{
	vector <Book> books;
public:
	void addBook(Book newBook);
	void removeBook(string title);
	void showAllBooks();
	void findBook(string query);
	void saveData(string filename);
	void loadData(string filename);
};

