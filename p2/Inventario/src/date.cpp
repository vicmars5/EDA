#include <iostream>
#include "date.h"

Date::Date() {
    day=0;
    month=0;
    year=0;
    }

Date::~Date() {
    //dtor
    }

void Date::setDate(int &d, int &m, int &y) {


    if(d>0 && m>0) {
        if((m==4 || m==6 || m==9 || m==11) && d<=30) {
            saveDate(d, m, y);
            }
        else {
            if((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && d<=31) {
                saveDate(d, m, y);
                }
            else {
                if((y%4) != 0) {
                    //Normal year
                    if(d<=28 && m==2) {
                        saveDate(d, m, y);
                        }
                    else {
                        throw DateException("ERROR, INVALID DATE");
                        }
                    }
                else {
                    //Leap year
                    if(d<=29 && m==2) {
                        saveDate(d, m, y);
                        }
                    else {
                        throw DateException("ERROR, INVALID DATE");
                        }
                    }
                }
            }
        }
    else {
        throw DateException("ERROR, INVALID DATE");
        }
    }

void Date::saveDate(int &d, int &m, int &y) {
    day=d;
    month=m;
    year=y;
    }

bool Date::isDate() {
    if(day != 0 && month != 0 && year != 0 ) {
        return true;
        }
    else {
        return false;
        }
    }

int Date::getDay() {
    if(isDate()) {
        return day;
        }
    else {
        throw DateException("ERROR, BUFFER UNDERRUN");
        }
    }

int Date::getMonth() {
    if(isDate()) {
        return month;
        }
    else {
        throw DateException("ERROR, BUFFER UNDERRUN");
        }
    }

int Date::getYear() {
    if(isDate()) {
        return year;
        }
    else {
        throw DateException("ERROR, BUFFER UNDERRUN");
        }
    }
