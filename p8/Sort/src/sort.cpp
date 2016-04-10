#include "sort.h"

#include <ctime>

float Sort::bubbleTime(int* arr, int s) {
    float startTime;
    startTime = getElapsedTimeInMs();
    bubble(arr, s);
    return getElapsedTimeInMs() - startTime;
}

float Sort::insertTime(int* arr, int s) {
    float startTime;
    startTime = getElapsedTimeInMs();
    insertSort(arr, s);
    return getElapsedTimeInMs() - startTime;
}

float Sort::quickTime(int* arr, int extI, int extD) {
    float startTime;
    startTime = getElapsedTimeInMs(); //Hora comienzo
    quick(arr, extI, extD);
    return getElapsedTimeInMs() - startTime; //Hora fin
}

float Sort::mergeTime(int* arr, int extI, int extD, int s) {
    float startTime = getElapsedTimeInMs(); //Hora comienzo
    mergeSort(arr, extI, extD, s);
    return getElapsedTimeInMs() - startTime; //Hora fin
}

float Sort::selectTime(int* arr, int s) {
    float startTime = getElapsedTimeInMs();
    selectSort(arr, s);
    return getElapsedTimeInMs() - startTime;
}

float Sort::shellTime(int* arr, int s) {
    float startTime = getElapsedTimeInMs();
    shell(arr, s);
    return getElapsedTimeInMs() - startTime;
}


void Sort::bubble(int* arr, const int& s) {
    int i = (s-1),
        j;
    bool seguir;
    do {
        seguir = false;
        j = 0;
        while ( j < i) {
            if (arr[j] > arr[j + 1]) {
                exchange(arr[j], arr[j + 1]);
                seguir = true;
            }

            j++;
        }

        i--;
    } while (seguir);
}

void Sort::insertSort(int* arr, const int& s) {
    int i = 1,
        j,
        last = s - 1;
    int aux;


    while (i <= last) {
        aux = arr[i];

        j = i;

        while (j > 0 and aux < arr[j-1]) {
            arr[j] = arr [j-1];
            j--;
        }
        if(i != j) {
            arr[j] = aux;
        }
        i++;
    }
}

void Sort::quick(int* arr, int extI, int extD) {
    int i, j;

    if (extI >= extD) {
        return;
    }

    exchange(arr[(extI + extD) / 2], arr[extD]);

    i = extI;
    j = extD;

    while (i < j) {
        while (i < j and arr[i] <= arr[extD]) {
            i++;
        }

        while (i < j and arr[j] >= arr[extD]) {
            j--;
        }

        if (i != j) {
            exchange(arr[i], arr[j]);
        }
    }

    if (i != extD) {
        exchange(arr[i], arr[extD]);
    }

    quick(arr, extI, (i - 1));
    quick(arr, (i + 1), extD);

}

void Sort::mergeSort(int* arr, int extI, int extD, int s) {
    if (extI < extD) {
        int m = (extI + extD) / 2;
        mergeSort(arr, extI, m, s);
        mergeSort(arr, m+1, extD, s);
        mergeS(arr, extI, m, extD, s);
    }
}

void Sort::mergeS(int* arr, int extI, int m, int extD, int s) {
    int i, j, k;
    int temp[s];

    for (i = extI; i <= extD; i++) {
        temp[i] = arr[i];
    }

    i = extI;
    j = m + 1;
    k = extI;

    while (i <= m and j <= extD) {
        if (temp[i] <=  temp[j]) {
            arr[k++] = temp[i++];
        } else {
            arr[k++] = temp[j++];
        }
    }

    while (i <= m) {
        arr[k++] = temp[i++];
    }
}

void Sort::selectSort(int* arr, const int& s)
{
    int last = s - 1;
    int i = 0,
        j;
    int smaller;

    while (i < last) {
        smaller = i;

        j = i + 1;
        while (j <= last) {
            if (arr[j] < arr [smaller]){
                smaller = j;
            }
            j++;
        }

        if (smaller != i) {
            exchange(arr[i], arr[smaller]);
        }

        i++;
    }
}

void Sort::shell(int* arr, const int& s)
{
    float fact = 3.0/4.0;
    int last = s - 1; //Ultimo indice
    int dif = last * fact;
    int i;

    while (dif > 0) {
        i = 0;

        while (i <= last - dif) {
            if(arr[i] > arr[i + dif]) {
                exchange(arr[i], arr[i + dif]);
            }
            i++;
        }
        dif = dif * fact;
    }
}


void Sort::exchange(int& a, int& b) {
    int c;

    c = a;
    a = b;
    b = c;
}

float Sort::getElapsedTimeInMs() {
    //Return clock() as ms
    //1 Second = 1000 milliseconds
    return clock()/(CLOCKS_PER_SEC/1000);
}

