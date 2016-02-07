#include "menu.h"
#include <iostream>
#include <string>

#include <product.h>
using namespace std;

Menu::Menu() {
    pCollection.initialize();
    }

Menu::~Menu() {
    //dtor
    }

void Menu::showMenu() {
    short option;
    bool finished=false;
    do {
        cout << "\tINVENTARIO" << endl
             << "1.-Añadir producto" << endl
             << "2.-Retirar producto" << endl
             << "3.-Añadir existencias a producto" << endl
             << "0.-Salir" << endl
             << "Elige una opción: ";
        cin >> option;
        cin.ignore();
        cout << endl << endl;

        switch(option) {
            case 1:
                addProduct();
                break;
            case 2:
                getProduct();
                break;
            case 3:
                addProductStock();
                break;
            case 0:
                finished=true;
                break;
            default:
                break;
            }
        }
    while(!finished);
    }

void Menu::addProduct() {
    Product product;
    int day, month, year;
    bool answerError;

    cout << "\tPRODUCTO" << endl;

    do {
        cout << "Codigo de barras: ";
        getline(cin, product.barCode);

        if(product.barCode.size()==11) {
            answerError = false;
            }
        else {
            cout << "ERROR, el codigo de barras no es de 11 digitos" << endl;
            answerError = true;
            }
        }
    while(answerError);

    do {
        cout << "Nombre: ";
        getline(cin, product.name);

        if(product.name != "") {
            answerError = false;
            }
        else {
            cout << "ERROR, por favor teclee el nombre" << endl;
            answerError = true;
            }

        }
    while(answerError);

    do {
        cout << "Peso (Kgs.): ";
        cin >> product.weight;

        if(product.weight >  0) {
            answerError = false;
            }
        else {
            cout << "ERROR, el peso no puede ser igual o menor a cero" << endl;
            answerError = true;
            }
        }
    while(answerError);

    do {
        cout << "Fecha " << endl;
        cout << "Dia: ";
        cin >> day;
        cout << "Month: ";
        cin >> month;
        cout << "Year: ";
        cin >> year;

        try {
            product.enterDate.setDate(day,month,year);
            answerError=false;
            }
        catch(DateException ex) {
            cout << "FECHA NO VALIDA" << endl;
            answerError=true;
            }
        }
    while(answerError);

    do {
        cout << "Precio mayoreo: ";
        cin >> product.wholesalePrice;

        if(product.wholesalePrice > 0) {
            answerError = false;
            }
        else {
            cout << "ERROR, el precio no puede ser menor o igual a cero" << endl;
            answerError = true;
            }
        }
    while(answerError);

    do {
        cout << "Precio menudeo: ";
        cin >> product.retailPrice;

        if(product.retailPrice > 0) {
            answerError = false;
            }
        else {
            cout << "ERROR, el precio no puede ser menor o igual a cero" << endl;
            answerError = true;
            }
        }
    while(answerError);

    do {
        cout << "Existencias: ";
        cin >> product.stock;
        if(product.stock>=0) {
            answerError=false;
            }
        else {
            answerError=true;
            }
        }
    while(answerError);

    pCollection.insertData(pCollection.getLastPos(), product);
    cout << "Producto guardado... " << endl << endl;
    }

void Menu::getProduct() {
    Product product;
    cout << "\tObtener producto" << endl
         << "codigo de barras del producto: ";
    getline(cin, product.barCode);

    try {
        product=pCollection.retrieve(pCollection.findData(product.barCode));

        cout << "Codigo de barras " << product.barCode << endl
             << "Nombre " << product.name << endl
             << "Peso " << product.weight << endl
             << "Fecha ingreso " << product.enterDate.getDay()
             << "-" << product.enterDate.getMonth()
             << "-" << product.enterDate.getYear() << endl
             << "Precio mayoreo " << product.wholesalePrice << endl
             << "Precio menudeo " << product.retailPrice << endl;

        if(product.stock>0) {
            product.stock--;
            pCollection.deleteData(pCollection.findData(product.barCode));
            pCollection.insertData(pCollection.getLastPos(), product);
            cout << "Existencias" << product.stock << endl;
            }
        else {
            cout << "Existencias" << product.stock << endl;
            cout << "SIN EXISTENCIAS" << endl << endl;
            }
        }
    catch(ProductsCollectionException ex) {
        cout << "ERROR, no se pudo insertar el producto" << endl;
        }
    cout << endl << endl;
    }


void Menu::addProductStock() {
    Product product;

    cout << "Ingresa el codigo de barras del producto";
    getline(cin, product.barCode);
    try {
        product=pCollection.retrieve(pCollection.findData(product.barCode));
        cout << "Ingrese las existencias ";
        cin >> product.stock;
        pCollection.deleteData(pCollection.findData(product.barCode));
        pCollection.insertData(pCollection.getLastPos(), product);

        }
    catch(ProductsCollectionException ex) {
        cout << "ERROR, no se pudo guardar las existencias" << endl;
        }
    cout << endl << endl;
    }
