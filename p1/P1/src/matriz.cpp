#include "matriz.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

Matriz::Matriz()
{
}

Matriz::~Matriz()
{
    //dtor
}

void Matriz::mostrarMatrices()
{
    int cont, subCont, mat=0;
    do
    {
        cout << "\t MatriZz: " << mat+1 << endl;
        for (cont=0; cont < tam; cont++){
            cout << "\t";
            for(subCont=0; subCont < tam; subCont++){
                cout << floorf((matriz[mat][cont][subCont]*100))/100 << " ";
            }
            cout << endl;
        }
        if(mat==0)        {
            cout << "\n\t    *" << endl;
        }
        else
        {
            if(mat==1)
            {
                cout << "\n\t    =" << endl;
            }
        }
        cout << endl;
        mat++;
    }
    while(mat<3);
}


void Matriz::multiplicarMatrices()
{
    int cont, subCont, tercerCont,mat=0;
    float suma;
    cout << "\t Matriz: " << mat+1 << endl;
    for (cont=0; cont < tam; cont++)
    {
        cout << "\t";
        for(subCont=0; subCont < tam; subCont++)
        {
            for(tercerCont=0; tercerCont < tam; tercerCont++)
            {
                suma+=matriz[0][subCont][tercerCont]*matriz[1][tercerCont][cont];
            }
            matriz[2][subCont][cont]=suma;
            suma=0;
        }
        cout << endl;
    }
    cout << endl;
    mat++;

}

void Matriz::crearMatrices()
{
    int cont, subCont;
    bool repetir=true;
    do
    {
        cout << "Define el tamaño de las matrices (de 3 a 10)" << endl;
        cin >> tam;
        cin.ignore();

        if(3<=tam && tam<=10)
        {
            for (cont=0; cont < tam; cont++)
            {
                for(subCont=0; subCont < tam; subCont++)
                {
                    matriz[0][cont][subCont]=(1+rand()%(10001-1))*0.01;
                    matriz[1][cont][subCont]=(1+rand()%(10001-1))*0.01;
                }
            }
            multiplicarMatrices();
            mostrarMatrices();
            repetir=false;
        }
        else
        {
            cout << "El numero que ingreso no es valido";
        }
    }
    while(repetir);
}
