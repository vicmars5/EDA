#include <iostream>

#include "list.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{

    Queue<int> q;
    Stack<int> s;

    cout << "Datos"<< endl;
    try{
        for(int i = 0; i < 10; i++) {
            q.enqueue(i);
            s.push(i);
            cout << i << ", ";

        }
    } catch(StackException ex) {
        cout << "NO SE PUEDE INSERTAR EN LA COLA";
    }

    cout << endl << endl;

    cout << "Cola" << endl;
    try {
        for(int i = 0; i < 10; i++) {
            cout << q.dequeue() << ", ";
        }
    } catch (StackException ex){
        cout << "LA COLA ESTA VACIA" << endl;
    }

    cout << endl << endl;
    cout << "Pila" << endl;
    try {
        for(int i = 0; i < 10; i++) {
            cout << s.pop() << ", ";
        }
    } catch (StackException ex){
        cout << "LA COLA ESTA VACIA" << endl;
    }

    return 0;
}
