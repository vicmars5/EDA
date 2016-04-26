#include <iostream>

#include "binaryTree.h"

using namespace std;

int main() {
    BinaryTree<int> myTree;

    for (int i = 0; i < 100; i++){
        cout << "Ingresando el dato " << i << endl;
        myTree.insertData(i);
    }
    cin.get();

    cout << endl << endl;
    myTree.preorder();
    cin.get();
    return 0;
}
