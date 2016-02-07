#include <iostream>
#include "cola.h";
using namespace std;

int main()
{
    Cola <int> cola;

    cout << "Valor " << cola.getFront() << endl;
    return 0;
}
