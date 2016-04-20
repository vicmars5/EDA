#include <iostream>

#include "queue.h"
#include "stack.h"

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

Queue<char> myQueue;
Stack<char> myStack;



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
    char comp;
    for(int i=0; i < cadena.size(); i++) {
        comp=cadena.at(i);
        if(esNumero(comp) or esVariable(comp)) {

            myQueue.enqueue(comp);
        } else {
            if(parentesisI(comp)) {

                myStack.push(comp);
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

    while(!myStack.isEmpty()) {
        myQueue.enqueue(myStack.pop());
    }

    while(!myQueue.isEmpty()) {
        cout << myQueue.dequeue();
    }

    cout << endl << endl;
}

void extraerHastaParentIzq() {
    while(myStack.getTop() != '(' && !myStack.isEmpty()) {
        myQueue.enqueue(myStack.pop());
    }

    if(myStack.getTop() == '(') {
        myStack.pop();
    }
}

void extraerOperadores(char op) {
    while(!myStack.isEmpty() && (precedencia(myStack.getTop()) >= precedencia(op) )) {
        myQueue.enqueue(myStack.pop());
    }

    myStack.push(op);
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
