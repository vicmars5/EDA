#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>

class StackException : public std::exception{
private:
    std::string msg;
public:
    explicit StackException(const char* message) : msg(message){}
    explicit StackException(const std::string& message) :msg(message) {}
    virtual ~StackException() throw () {}
    virtual const char* what() const throw () { return msg.c_str();}
};

template <class T, int arraySize=1024>
class Stack{
    private:
    T data[araySize];
    int last
public:
    Stack();
    bool isEmpty();
    bool isFull();

    void push(const T&);
    void pop();

    T getTop();
};


#endif // STACK_H_INCLUDED
