#include "Library.h"
#include "Book.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
void Library::addBook(Book newBook)
{
	books.push_back(newBook);
};
void Library::removeBook(string title)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getTitle() == title)
		{
			books.erase(books.begin() + i);
		}
	}
};
void Library::showAllBooks()
{
	setlocale(LC_ALL, "russian");
	if (books.empty())
	{
		cout << "Список книг пуст" << endl;
	}
	else
	{
		for (int i = 0; i < books.size(); i++)
		{
			cout << books[i].getInfo() << endl;
		}
	}

}
void Library::findBook(string query)
{
	bool Flag_find = false;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getTitle() == query)
		{
			Flag_find = true;
			cout << books[i].getInfo() << endl;
		}
	}
	if (!Flag_find)
	{
		setlocale(LC_ALL, "russian");
		cout << "Книга не найдена" << endl;
	}
}
void Library::saveData(string filename)
{
	setlocale(LC_ALL, "russian");
	// Открываем файл для записи (по умолчанию он очистится перед записью)
	ofstream A(filename);

	if (A.is_open())
	{
		for (int i = 0; i < books.size(); i++)
		{
			// Мы вручную "разбираем" книгу на части и записываем их
			A << books[i].getTitle() << ";"
				<< books[i].getAuthor() << ";"
				<< books[i].getYear() << ";"
				<< books[i].getGenre() << "\n"; // В конце перенос строки
		}
		A.close(); // Обязательно закрываем файл
		cout << "Данные успешно сохранены!" << endl;
	}
	else
	{
		cout << "Ошибка открытия файла для записи!" << endl;
	}
}

void Library::loadData(string filename)
{	
	setlocale(LC_ALL, "russian");
	books.clear();

	ifstream A(filename);

	if (!A.is_open())
	{
		cout << "Файл не найден. Библиотека будет создана заново." << endl;
		return;
	}

	string line;

	while (getline(A, line))
	{
		if (line.empty())
		{
			continue;
		}

		string title;
		string author;
		string yearStr;
		string genre;

		stringstream ss(line);

		getline(ss, title, ';');
		getline(ss, author, ';');
		getline(ss, yearStr, ';');
		getline(ss, genre, ';');

		int year = stoi(yearStr);

		Book newBook(title, year, author, genre);
		books.push_back(newBook);
	}

	A.close();
	cout << "Данные успешно загружены!" << endl;
}