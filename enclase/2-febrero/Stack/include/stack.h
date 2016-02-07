#ifndef STACK_H
#define STACK_H

#include <exception>

template <class T, int arraySize=1024>
class Stack{
private:
    T data[arraySize];
    int last;
public:
    Stack();
    bool isEmpty();
    bool isFull();

    void push(const T&);
    void pop();

    T getTop();
};


#endif // STACK_H
