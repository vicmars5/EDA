#ifndef DATE_H
#define DATE_H

#include <string>
#include <exception>

using namespace std;

class DateException : public std::exception {
    private:
        std::string msg;
    public:
        explicit DateException(const char* message) : msg(message) {}
        explicit DateException(const std::string& message) :msg(message) {}
        virtual ~DateException() throw () {}
        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

class Date {
    public:
        Date();
        virtual ~Date();
        void setDate(int&, int&, int&);
        int getDay();
        int getMonth();
        int getYear();
    protected:
        int day;
        int month;
        int year;
        void saveDate(int &, int&, int&);
        bool isDate();
    private:
    };

#endif // DATE_H
