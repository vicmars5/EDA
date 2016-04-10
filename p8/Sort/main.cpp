#include <iostream>
#include <cstdlib>
#include <ctime>

#include "sort.h"

#define A_SIZE 65536

using namespace std;

float getElapsedTimeInMs();
void mostrarArreglo(int* arr);
void llenaArreglo(int* arr);
void copiarArreglo(int* orig, int* cop);

int main()
{
    int arrBubble[A_SIZE],
        arrShell[A_SIZE],
        arrInsert[A_SIZE],
        arrSelect[A_SIZE],
        arrMerge[A_SIZE],
        arrQuick[A_SIZE];
    int startTime, elapsedTime;

    Sort mySort;

    srand(time(NULL));

    llenaArreglo(arrBubble);
    copiarArreglo(arrBubble, arrInsert);
    copiarArreglo(arrBubble, arrQuick);
    copiarArreglo(arrBubble, arrSelect);
    copiarArreglo(arrBubble, arrShell);

    cout << "\tBurbuja" << endl
            << " Insertando datos..." << endl
            << " Ordenando..." << endl;
    elapsedTime = mySort.bubbleTime(arrBubble, A_SIZE);
    cout << " Tiempo " << elapsedTime << " milisegundos" << endl << endl;

    cout << "\tInsert" << endl
            << " Insertando datos..." << endl
            << " Ordenando..." << endl;
    elapsedTime = mySort.bubbleTime(arrInsert, A_SIZE);
    cout << " Tiempo " << elapsedTime << " milisegundos" << endl << endl;

    cout << "\tQuick Sort" << endl
            << " Insertando datos..." << endl
            << " Ordenando..." << endl;
    elapsedTime = mySort.quickTime(arrQuick, 0, (A_SIZE-1));
    cout << " Tiempo " << elapsedTime << " milisegundos" << endl << endl;

    cout << "\tMerge Sort" << endl
            << " Insertando datos..." << endl
            << " Ordenando..." << endl;
    elapsedTime = mySort.mergeTime(arrMerge, 0, (A_SIZE-1), A_SIZE);
    cout << " Tiempo " << elapsedTime << " milisegundos" << endl << endl;

    cout << "\tSelección" << endl
            << " Insertando datos..." << endl
            << " Ordenando..." << endl;
    elapsedTime = mySort.selectTime(arrSelect, A_SIZE);
    cout << " Tiempo " << elapsedTime << " milisegundos" << endl << endl;

    cout << "\tShell" << endl
            << " Insertando datos..." << endl
            << " Ordenando..." << endl;
    elapsedTime = mySort.shellTime(arrShell, A_SIZE);
    cout << " Tiempo " << elapsedTime << " milisegundos" << endl << endl;

    return 0;
}

void mostrarArreglo(int* arr){
    for (int i = 0; i < A_SIZE; i++) {
        cout << arr[i] << " ";
    }
}

void llenaArreglo(int* arr) {
    for (int i = 0; i < A_SIZE; i++) {
        arr[i] = rand() % A_SIZE;
    }
}

void copiarArreglo(int* orig, int* cop) {
    for (int i = 0; i < A_SIZE; i++) {
        cop[i] = orig[i];
    }
}


