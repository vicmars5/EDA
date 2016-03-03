#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date();
        virtual ~Date();
        bool isDate(const int&, const int&, const int&);
    private:
        int codigoErrorFecha;
};

#endif // DATE_H
