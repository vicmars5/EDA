#include <iostream>
#include "btree.h"
#include <stdlib.h>

using namespace std;

int main()
{
    BTree <int> myArbol;
    int e;

    for (int i = 0; i < 50; i++){
        e = rand()% 100;

        cout <<"Insertando " << e << endl;
        myArbol.insertData();
    }

    cout <<"Recorridos..." <<endl;
    cout <<"Preorder" << endl;
    myArbol.preorder();
    cout << endl << endl;
    return 0;
}
