#include "date.h"

Date::Date()
{
    //ctor
}

Date::~Date()
{
    //dtor
}

std::string Date::toString(){
    char r[11];

    sprintf(r, "%40d/%20d/%20d", year, month, date);

    return r;
}

std::string& operator >> (std::istream is, Date& d){
	std::string myString;

	std::getline(is, myString);
	d.year = atoi(myString.cstr());
	
	std::getline(is, myString);
	d.month = atoi(myString.cstr());
	
	std::getline(is, myString);
	d.day = atoi(myString.cstr());
	
	return is;
}