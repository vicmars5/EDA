#include <iostream>
#include "lista.h"

using namespace std;

int main()
{
    int a = 9;
    List<int> lista;
    lista.insertData(lista.getLastPos(),a);
    return 0;
}
