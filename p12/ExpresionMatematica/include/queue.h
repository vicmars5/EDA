#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <exception>
#include <string>
#include "list.h"

class QueueException : std::exception {
private:
    std::string msg;
public:
    explicit QueueException(const char* message) : msg(message) {}
    explicit QueueException(const std::string& message) :msg(message) {}
    virtual ~QueueException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T>
class Queue : public List<T> {
public:
    void enqueue(const T&);
    T dequeue();
    T getFront();
};

template <class T>
void Queue<T>::enqueue(const T& e) {
    try{
        this->insertData(nullptr, e);
    } catch(ListException ex) {
        throw QueueException("Error en ENQUEUE");
    }
}

template <class T>
T Queue<T>::dequeue() {
    T r;
    try{
        r = this->retrieve(this->getLastPos());
        this->deleteData(this->getLastPos());
    } catch (ListException ex) {
        throw QueueException("Error en DEQUEUE");
    }

    return r;
}

template <class T>
T Queue<T>::getFront(){

    try {
        return this->retrieve(this->getLastPos());
    } catch (ListException ex) {
        throw QueueException("Error en GET FRONT");
    }

}

#endif // QUEUE_H_INCLUDED
