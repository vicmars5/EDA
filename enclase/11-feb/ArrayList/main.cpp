#include <iostream>
#include <cstdlib>
#include "list.h";

using namespace std;

int main()
{
    List<int, 500> myList;
    List<float, 200> myOtherList;

    int myData;

    //INsertar 20 enteros
    for(int i=0; i<20; i++){
        myData=rand() % 100;

        cout << "Insertando el valor " << myData << endl;

        myList.insertData(myList.getLastPos(), myData);
    }

    cout << endl << endl;
    cout << "El contenido de la lista es:" << endl;

    myList.printData();

    cout << endl;

    try{
        myList.insertData(50, 385);
    }
    catch(ListException ex){
        cout << "Ups, algo no salio bien " << endl;
        cout << "EL sistema dice que : \"" << ex.what() << "\"" << endl;
        ///***Que hacer si hay una excepcion
    }
    cout << endl << endl;

    cout << "Dame un valor: ";
    cin >> myData;

    myPos= myList.findData(myData);

    if(myPos = -1){
        cout << "El elemento que buscas no existe ene la lista" << endl;
    }
    else{
        cout << "El elemento " << myData << " esta en la posicion " << myPos << " de la lista" << endl;
    }
    return 0;
}
