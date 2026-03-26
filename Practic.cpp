#include <iostream>
#include <string>
#include <limits>
#include "Library.h"
#include "Book.h"
#include <windows.h>
#include <clocale>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Library myLib;
    myLib.loadData("library.txt");

    while (true)
    {
        cout << "\n=== БИБЛИОТЕКА ===\n";
        cout << "1. Добавить книгу\n";
        cout << "2. Показать все книги\n";
        cout << "3. Найти книгу\n";
        cout << "4. Удалить книгу\n";
        cout << "5. Сохранить и выйти\n";
        cout << "Выберите пункт: ";

        string choiceStr;
        getline(cin, choiceStr);
        int choice = stoi(choiceStr);

        if (choice == 1)
        {
            string title;
            string author;
            string genre;

            cout << "Введите название книги: ";
            getline(cin, title);

            cout << "Введите автора: ";
            getline(cin, author);

            cout << "Введите год издания: ";
            string yearStr;
            getline(cin, yearStr);
            int year = stoi(yearStr);

            cout << "Введите жанр: ";
            getline(cin, genre);

            Book newBook(title, year, author, genre);
            myLib.addBook(newBook);

            cout << "Книга добавлена.\n";
        }
        else if (choice == 2)
        {
            myLib.showAllBooks();
        }
        else if (choice == 3)
        {
            string query;
            cout << "Введите название книги для поиска: ";
            getline(cin, query);
            myLib.findBook(query);
        }
        else if (choice == 4)
        {
            string title;
            cout << "Введите название книги для удаления: ";
            getline(cin, title);
            myLib.removeBook(title);
        }
        else if (choice == 5)
        {
            myLib.saveData("library.txt");
            cout << "Программа завершена.\n";
            break;
        }
        else
        {
            cout << "Неверный пункт меню. Попробуйте снова.\n";
        }
    }

    return 0;
}