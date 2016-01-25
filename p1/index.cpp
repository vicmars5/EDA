#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
using namespace std;

int main(){
	unsigned char eleccion;
	float algo;
	do{
		cout << "\t\tActividad 1. Por Diaz Mendez Víctor Agustín" << endl;
		cout << "Opciones: " << endl;
		cout << "\ta)Tamaño y rangos de los Tipos de Datos Primitivos" << endl;
		cout << "\tb)Ejemplo de uso de Tipo de dato Estructurado" << endl;
		cout << "\tc) Salir" << endl;
		cin >> eleccion;
		switch(eleccion){
			case 'a':
			case 'A':
				cout << "Tipo de dato			Bits		Valor minimo		Valor maximo" << endl;
				cout <<	"Caracter con signo		"<< sizeof(char) <<"		" << SCHAR_MIN<< "			"<<SCHAR_MAX << endl;
				cout <<	"Caracter sin signo		"<< sizeof(unsigned char) <<"		0			" <<  UCHAR_MAX << endl;
				cout <<	"Entero corto con signo		"<< sizeof(short) <<"		" << SHRT_MIN << "			" << SHRT_MAX << endl;
				cout <<	"Entero corto sin signo		"<< sizeof(unsigned short) <<"		0			" << USHRT_MAX << endl;
				cout <<	"Entero largo con signo		"<< sizeof(long) <<"		" << LONG_MIN << "	" << LONG_MAX << endl;
				cout <<	"Entero largo sin signo		"<< sizeof(unsigned long) <<"		0			" << ULONG_MAX << endl;
				cout <<	"Real de precision simple	"<< sizeof(float) <<"		" << FLT_MIN <<"		" << FLT_MAX << endl;
				cout <<	"Real de precision doble		"<< sizeof(double) <<"		" << DBL_MIN << "		" << DBL_MAX << endl;
				break;
			case 'b':
			case 'B':
					cout << SHRT_MIN;
				break;
		}
	}while(eleccion!='c' && eleccion!='C');
	return 0;
}