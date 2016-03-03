#include "name.h"

Name::Name()
{
    //ctor
}

Name::~Name()
{
    //dtor
}

std::istream& operator >> (std::istream& is, Name& n){
    string myString;

    std::getline(is, myString);
    n.first=atoi(myString.cstr());

    std::getline(is, myString);
    n.last=atoi(myString.cstr());
}
