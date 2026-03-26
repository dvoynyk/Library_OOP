#pragma once
#include <string>
using namespace std;
class Publication
{
	string title;
	int year;
public:
	Publication(string title, int year);
	string getInfo();
	string getTitle();
	int getYear();
};

