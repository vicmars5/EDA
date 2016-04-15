#ifndef STACK_H
#define STACK_H

#include <exception>

#include "list.h"

class StackException : public std::exception {
    private:

    public:
}

template <class T>
class Stack : public List<T> {
public:
    void push(const T&);
    T& pop();

    T& getTop();
};

template <class T>
void Stack<T>::push(const T& e)
{
    try {
        this->insertData(nullptr, e);
    } catch (ListException ex) {
        StackException("Memoria no disponible en PUSH")
    }
}

template <class T>
T& Stack<T>::pop()
{
    T
    try{
        r = this->retrieve(this->getPosition());
        this->deleteData(this->getFirstPos());
    } catch (ListException ex) {
        StackException("No se que paso");
    }
    return r;
}

template <class T>
T& Stack<T>::getTop()
{
    try{
        return this->retrieve(this->getFirstPos());
    } catch (ListException ex){
        StackException("Problema al hacer GET TOP");
    }
}


#endif // STACK_H
