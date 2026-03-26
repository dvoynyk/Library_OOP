#pragma once
#include <string>
#include "Publication.h"
class Book : public Publication
{
	string author;
	string genre;
public:
	Book(string title, int year, string author, string genre);
	string getInfo();
	string getAuthor();
	string getGenre();
};

