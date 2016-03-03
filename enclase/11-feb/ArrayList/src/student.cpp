#include "student.h"

Student::Student()
{
    //ctor
}

Student::~Student()
{
    //dtor
}
>> (std::istream& is, Student& s){
    std::string myString;

    std::getline(is, s.code);
    is >> s.name;
    std::getline(is, s.career);
    is >> s.birthDate;
    is >> s.startDate;
    std::getline(is,myString);
    s.score = atof(myString.c_str());
}
