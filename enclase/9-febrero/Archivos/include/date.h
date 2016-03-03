#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
    public:
        Date();
        Date(const Date&);///copiable

        int getDay();
        int getMonth();
        int getYear();

        void setDay(const int&);
        void setMonth(const int&);
        void setYear(const int&);

        ///Comparable
        bool operator == (const Date&);
        bool operator != (const Date&);
        bool operator > (const Date&);
        bool operator <= (const Date&);
        bool operator >= (const Date&);
        bool operator < (const Date&);

        friend std::ostream& operator << (std::ostream&,  Date&);
        friend std::istream& operator >> (std::istream&, Date&);

    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
