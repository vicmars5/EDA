#include <iostream>
#include <string>

#include "list.h"
#include "student.h"
#include "name.h"

using namespace std;

int main() {
    List<Student> myLista;
    char op
    string myString;
    Student myStudent;
    Name myName;
    Date myDate;
    int myInt;

    do {
        cout << "Dame el codigo ";
        getline(cin, myString);
        myStudent.setCode(myString);

        cout << "Dame el apellido: ";
        getline(cin, myString);
        myName.setLast(myString);

        cout << "Dame el nombre: ";
        getline(cin, myString);
        myName.setFirst(myString);

        myStudent.setName(myName);

        cout << "Dame la carrera: ";
        getline(cin, myString);
        myStudent.setCareer(myString);

        cout << "Dame el dia de nacimiento: " << endl;
        cin >> myInt;
        myDate.setMonth(myInt);

        cout << "Dame el mes de nacimiento" << endl;
        cin >> myInt;
        myDate.setMonth(myInt);

        cout << "Dame el año de nacimiento" << endl;
        cin >> myInt;
        myDate.setYear(myInt);

        myStudent.setBithdate(myDate);

        cout << "Dame el dia de ingreso: " << endl;
        cin >> myInt;
        myDate.setMonth(myInt);

        cout << "Dame el mes de ingreso" << endl;
        cin >> myInt;
        myDate.setMonth(myInt);

        cout << "Dame el año de ingreso" << endl;
        cin >> myInt;
        myDate.setYear(myInt);

        myStudent.setStartDate(myDate);

        cout << "Dame el promedio" << endl;
        cin >> myFloat();
        myStudent.setScore(myFloat);

        myLista.insertData(myLista.getLastPos(), myStudent);

        do {
            cout << "Capturar otro (S/N): ";
            cin >> op;

            cin.ignore();

            op = toupper(op);
        } while(op != 'N' && op != 'S');

        cout << endl << endl;
        cout << "Contenido de la lista: " << endl;

        cout << "Escribiendo a disco... " << endl;
        myLista.writeToDisk("students.chin");


    } while(op == 'S');

    return 0;
}
