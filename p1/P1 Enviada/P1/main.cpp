#include <iostream>
#include <string>
#include "matriz.h"
#include "tiposDatos.h"

using namespace std;

int main(){
	unsigned char eleccion;
	float algo;
    TiposDatos t;
    Matriz m;
	do{
		cout << "\t\tActividad 1. Por Diaz Mendez Víctor Agustín" << endl;
		cout << "Opciones: " << endl;
		cout << "\ta)Tamaño y rangos de los Tipos de Datos Primitivos" << endl;
		cout << "\tb)Ejemplo de uso de Tipo de dato Estructurado" << endl;
		cout << "\tc) Salir" << endl;
		cin >> eleccion;
		cin.ignore();
		switch(eleccion){
			case 'a':
			case 'A':
                t.mostrarTiposDatos();
				break;
			case 'b':
			case 'B':
                m.crearMatrices();
				break;
		}
	}while(eleccion!='c' && eleccion!='C');
	return 0;
}
