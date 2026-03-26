#include "Book.h"
#include "Publication.h"
#include <string>
using namespace std;

// Исправленный конструктор
Book::Book(string title, int year, string author, string genre) : Publication(title, year) // Вызываем конструктор родителя правильно
{
    this->author = author;
    this->genre = genre;
}

string Book::getInfo()
{
    // Здесь можно использовать getTitle() и getYear() от родителя
    return "Книга: " + getTitle() + ", Год: " + to_string(getYear()) + ", Автор: " + author + ", Жанр: " + genre;
}

string Book::getAuthor() {
    return author;
}

string Book::getGenre() {
    return genre;
}