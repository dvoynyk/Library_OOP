#include "Publication.h"
#include <string>
using namespace std;
Publication::Publication(string title, int year)
{
	this->title = title;
	this->year = year;
}
string Publication::getInfo()
{
	return "";
}
string Publication::getTitle()
{
	return title;
}
int Publication::getYear()
{
	return year;
}