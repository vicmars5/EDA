#include "tiposDatos.h"
#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

TiposDatos::TiposDatos(){
}

TiposDatos::~TiposDatos(){
}

void TiposDatos::mostrarTiposDatos(){
    cout << "Tipo de dato			Bits	Valor minimo		Valor maximo" << endl;
    cout <<	"Caracter con signo		"<< sizeof(char)*8 <<"	" << SCHAR_MIN<< "			"<<SCHAR_MAX << endl;
    cout <<	"Caracter sin signo		"<< sizeof(unsigned char)*8 <<"	0			" <<  UCHAR_MAX << endl;
    cout <<	"Entero corto con signo		"<< sizeof(short)*8 <<"	" << SHRT_MIN << "			" << SHRT_MAX << endl;
    cout <<	"Entero corto sin signo		"<< sizeof(unsigned short)*8 <<"	0			" << USHRT_MAX << endl;
    cout <<	"Entero largo con signo		"<< sizeof(long)*8 <<"	" << LONG_MIN << "	" << LONG_MAX << endl;
    cout <<	"Entero largo sin signo		"<< sizeof(unsigned long)*8 <<"	0			" << ULONG_MAX << endl;
    cout <<	"Real de precision simple	"<< sizeof(float)*8 <<"	" << FLT_MIN <<"		" << FLT_MAX << endl;
    cout <<	"Real de precision doble		"<< sizeof(double)*8 <<"	" << DBL_MIN << "		" << DBL_MAX << endl;
}
