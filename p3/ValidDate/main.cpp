#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    int day, month, year;
    Date d;
    cout << "Fecha: ";
    cin >> day >> month >> year;

    if(d.isDate(day, month, year)){
        cout << "Valid date" << endl;
    }
    else {
        cout << "Invalid date" << endl;
    }
    return 0;
}
