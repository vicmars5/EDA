#include <iostream>
#include "pila.h"
#include "cola.h"

using namespace std;

void convertirExpresion(const string& cadena);
bool esNumero(const char& c);
bool esVariable(const char& c);
bool parentesisI(const char& c);
bool parentesisD(const char& c);
bool esOperador(const char& c);
int precedencia(const char& c);
void extraerHastaParentIzq();
void extraerOperadores(char op);

Pila<char> miPila;
Cola<char> miCola;

int main() {

    string cadena;
    int repetir;
    do{
        cout << "Expresion " << endl;
        cin >> cadena;
        cin.ignore();
        convertirExpresion(cadena);

        cout << "¿Desea convertir otra expresion? (1/0)";
        cin >> repetir;
        cin.ignore();
    } while(repetir == 1);
    return 0;
}

void convertirExpresion(const string& cadena) {
    miPila.inicializa();
    miCola.inicializa();
    char comp;
    for(int i=0; i < cadena.size(); i++) {
        comp=cadena.at(i);
        if(esNumero(comp) or esVariable(comp)) {
            miCola.agregar(comp);
        } else {
            if(parentesisI(comp)) {
                ;
                miPila.apilar(comp);
            } else {
                if(parentesisD(comp)) {
                    extraerHastaParentIzq();
                } else {
                    if(esOperador(comp)) {
                        extraerOperadores(comp);
                    } else {
                    }
                }
            }
        }
    }
    while(!miPila.estaVacia()) {
        miCola.agregar(miPila.tope());
        miPila.desapilar();
    }
    while(!miCola.estaVacia()) {
        cout << miCola.obtenerFrente();
        miCola.eliminar();
    }

    cout << endl << endl;
}

void extraerHastaParentIzq() {
    while(miPila.tope() != '(' && !miPila.estaVacia()) {
        miCola.agregar(miPila.tope());
        miPila.desapilar();
    }
    if(miPila.tope() == '(') {
        miPila.desapilar();
    }
}

void extraerOperadores(char op) {
    while(!miPila.estaVacia() && (precedencia(miPila.tope()) >= precedencia(op))) {
        miCola.agregar(miPila.tope());
        miPila.desapilar();
    }
    miPila.apilar(op);
}

bool esNumero(const char& c) {
    return (c >= '0' and c <='9');
}

bool esVariable(const char& c) {
    return (c >= 'a' and c <= 'z') or ( c >= 'A' and c <= 'Z');
}

bool parentesisI(const char& c) {
    return (c == '(');
}

bool parentesisD(const char& c) {
    return (c == ')');
}

bool esOperador(const char& c) {
    return (precedencia(c) > 0);
}

int precedencia(const char& c) {
    if(c == '+' or c == '-') {
        return 1;
    } else {
        if(c == '*' or c == '/') {
            return 2;
        } else {
            if(c == '^') {
                return 3;
            } else {
                return 0;
            }
        }
    }
}
