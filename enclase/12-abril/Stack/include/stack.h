#ifndef STACK_H
#define STACK_H

#include <exception>

class StackException : public std::exception {
    private:

    public:
}

template <class T>
class Stack{
private:
    Node<T>* anchor;
public:
    Stack();
    ~Stack();

    Stack(const Stack&);

    bool isEmpty();
    bool isFull();

    void push(const T&);
    T& pop();

    T& getTop();
};

template <class T>
Stack<T>::Stack()
{
    anchor = nullptr;
}

template <class T>
Stack<T>::~Stack()
{
    Node<T>* aux;
    while(anchor != nullptr) {
        //ELIMINA
    }
}


template <class T>
Stack<T>::Stack(const Stack& s) : Stack()
{
    Node<T>* last = nullptr;
    Node<T>* auxN;
    Node<T>* auxR = s.anchor;

    while(aux != nullptr) {
        auxN = new Node<T>(auxR.getData());

        if(last == nullptr){
            anchor = auxN;
        } else {
            last->setNext(auxN);
        }
        last = auxN;
    }
}

template <class T>
bool Stack<T>::isEmpty()
{
    return anchor == nullptr;
}

template <class T>
bool Stack<T>::isFull()
{

}

template <class T>
void Stack<T>::push(const T&)
{
    Node<T>* aux = new Node<T>(e);
    if(aux == nullptr) {
        throw StackException("Memoria no disponible al hacer push");
    }

    aux->setNext(anchor);

    anchor = aux;
}

template <class T>
void Stack<T>::pop()
{
    if(isEmpty) {
        throw StackException("Pila vacia, tratando de hacer un POP");
    }

    T r = anchor->getData();

    Node<T>* aux = anchor;
    anchor= (anchor->getNext());

    delete aux;

    return r;
}

template <class T>
T Stack<T>::getTop()
{
    if(isEmpty()) {
        throw StackException("Pila vacia al tratar de hacer GET TOP");
    }

    return anchor->getData();
}


#endif // STACK_H
