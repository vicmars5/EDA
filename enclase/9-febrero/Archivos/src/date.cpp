#include "date.h"

Date::Date() {
    //Pendiente
}

Date::Date(const Date& d) {
    year = d.year;
    month = d.month;
    day = d.day;
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

void Date::setDay(const int& d) {
    day=d;
}

void Date::setMonth(const int& m) {
    month = m;
}

void Date::setYear(const int& y) {
    year=y;
}

bool Date::operator==(const Date& d) {

    return year == d.year and
           month == d.month and
           day == d.day;
}

bool Date::operator!=(const Date& d) {
    return !(*this == d);
}

bool Date::operator>(const Date& d) {
    return year * 10000 + month * 100 + day > d.year * 10000 + d.month * d.100 + day;
}

bool Date::operator>=(const Date&) {
    return year * 10000 + month * 100 + day >= d.year * 10000 + d.month * d.100 + day;

}

bool Date::operator<(const Date&) {
    return year * 10000 + month * 100 + day < d.year * 10000 + d.month * d.100 + day;

}

bool Date::operator<=(const Date&) {
    return year * 10000 + month * 100 + day <= d.year * 10000 + d.month * d.100 + day;

}

std::ostream& operator << (std::ostream& os,  Date&) {
    os << d.year << "/" << d.month << "/" << d.day;
}

std::istream& operator >> (std::istream& os, Date&) {
    ///pendiente
}
