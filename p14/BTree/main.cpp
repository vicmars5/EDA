#include <iostream>
#include <cstdlib>
#include <ctime>

#include "binaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> myTree;
    int insercion, cant;

    srand(time(NULL));

    cout << "Cuantos datos deseas ingresar al arbol? ";
    cin >> cant;
    cin.ignore();
    cout << endl << endl;

    for(int i = 0; i < cant; i++) {
        insercion = (rand() % 65536);
        cout << insercion << ", ";
        myTree.insertData(insercion);
    }
    cin.get();
    cout << endl;

    cout << "Inorder" << endl;
    myTree.inorder();
    cout << endl << endl;

    cout << "Postorder" << endl;
    myTree.postorder();
    cout << endl << endl;

    cout << "Preorder" << endl;
    myTree.preorder();
    cout << endl << endl;

    cout << "Altura subarbol izquierdo: " << myTree.getLeftHeight() << endl;
    cout << "Altura subarbol derecho: " << myTree.getRightHeight() << endl;

    cin.get();
    return 0;
}
