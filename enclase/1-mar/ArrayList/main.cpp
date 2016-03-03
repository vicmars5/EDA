#include <iostream>
#include <cstdlib>
#include "list.h";

using namespace std;

int main()
{
    List<int, 500> myList1, myList2, myList3, myList4, myList5, myList6;
    List<float, 200> myOtherList;

    int myData;

    myList1.initialize();
    myList2.initialize();
    myList3.initialize();
    myList4.initialize();
    myList5.initialize();
    myList6.initialize();

    //INsertar 20 enteros
    cout << "Lista 1" << endl;
    for(int i=0; i<20; i++){
        myData=rand() % 100;

        cout << "Insertando el valor " << myData << endl;
        myList1.insertData(myList1.getLastPos(), myData);
    }

    cout << endl << endl << "Lista 2" << endl;

    for(int i=0; i<20; i++){
        myData=rand() % 100;

        cout << "Insertando el valor " << myData << endl;
        myList2.insertData(myList2.getLastPos(), myData);
    }

    cout << endl << endl << "Lista 3" << endl;

    for(int i=0; i<20; i++){
        myData=rand() % 100;

        cout << "Insertando el valor " << myData << endl;
        myList3.insertData(myList3.getLastPos(), myData);
    }

    cout << endl << endl << "Lista 4" << endl;

    for(int i=0; i<20; i++){
        myData=rand() % 100;

        cout << "Insertando el valor " << myData << endl;
        myList4.insertData(myList4.getLastPos(), myData);
    }


    cout << endl << endl << "Lista 5" << endl;

    for(int i=0; i<20; i++){
        myData=rand() % 100;

        cout << "Insertando el valor " << myData << endl;
        myList5.insertData(myList5.getLastPos(), myData);
    }

    cout << endl << endl << "Lista 6" << endl;

    for(int i=0; i<20; i++){
        myData=rand() % 100;

        cout << "Insertando el valor " << myData << endl;
        myList6.insertData(myList6.getLastPos(), myData);
    }

    cout << endl << endl;
    cout << "El contenido de la lista es:" << endl;

    //myList.printData();

    cout << "Bubble: " << endl;
    myList1.sortDataBubble();
    myList1.printData();

    cout << "Shell: " << endl;
    myList2.sortData();
    myList2.printData();

    cout << "Insercion: " << endl;
    myList3.sortDataInsert();
    myList3.printData();

    cout << "Seleccion: " << endl;
    myList4.sortDataInsert();
    myList4.printData();

    cout << "Mezcla: " << endl;
    myList5.sortDataMerge();
    myList5.printData();


    cout << "QuickSort: " << endl;
    myList6.sortDataQuick();
    myList6.printData();

    cout << endl;
/*
    try{
        myList.insertData(50, 385);
    }
    catch(ListException ex){
        cout << "Ups, algo no salio bien " << endl;
        cout << "EL sistema dice que : \"" << ex.what() << "\"" << endl;
        ///***Que hacer si hay una excepcion
    }
    */
    cout << endl << endl;
    /*
    cout << "Dame un valor: ";
    cin >> myData;

    myPos= myList.findData(myData);

    if(myPos = -1){
        cout << "El elemento que buscas no existe ene la lista" << endl;
    }
    else{
        cout << "El elemento " << myData << " esta en la posicion " << myPos << " de la lista" << endl;
    }*/
    return 0;
}
