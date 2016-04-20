#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <exception>
#include <string>

class StackException : std::exception {
private:
    std::string msg;
public:
    explicit StackException(const char* message) : msg(message) {}
    explicit StackException(const std::string& message) :msg(message) {}
    virtual ~StackException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T>
class Stack : public List<T> {
    public:
        void push(const T&);
        T pop();

        T getTop();
};

template <class T>
void Stack<T>::push(const T& e) {
    try{
        this->insertData(nullptr, e);
    } catch(ListException ex) {
        throw StackException("Error al hacer PUSH");
    }
}

template <class T>
T Stack<T>::pop(){
    T r;
    try{
        r = this->retrieve(this->getFirstPos());
        this->deleteData(this->getFirstPos());
    } catch (ListException) {
        throw StackException("Error al hacer POP");
    }

    return r;
}

template <class T>
T Stack<T>::getTop(){
    try {
        return this->retrieve(this->getFirstPos());
    } catch(ListException ex) {
        throw StackException("Problema al hacer GET TOP");
    }
}

#endif // STACK_H_INCLUDED
