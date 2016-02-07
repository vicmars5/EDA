#ifndef COLA_H
#define COLA_H

#include <string>
#include <exception>

class QueueException : public std::exception{
private:
    std::string msg;
public:
    explicit QueueException(const char* message) : msg(message){}
    explicit QueueException(const std::string& message) :msg(message) {}
    virtual ~QueueException() throw () {}
    virtual const char* what() const throw () { return msg.c_str();}
};

template <class T, int  arraySize=1024>
class Cola
{
private:
    T data[arraySize];
    int frontPos;
    int endPos;
public:
    Cola();

    bool isEmpty();
    bool isFull();
    void enqueue(const T&);
    T dequeue();

    T getFront();
};

template <class T, int  arraySize>
Cola<T, arraySize>::Cola()
{
    frontPos=0;
    endPos=arraySize-1;
}

template <class T, int  arraySize>
bool Cola<T, arraySize>::isEmpty()
{
    return frontPos == endPos + 1 or
            (frontPos==0 and endPos == arraySize -1);
}

template <class T, int  arraySize>
bool Cola<T, arraySize>::isFull()
{
    return frontPos == endPos + 2 or
            (frontPos == 0 and endPos == arraySize - 2) or
            (frontPos == 1 and endPos == arraySize -1);
}

template <class T, int  arraySize>
void Cola<T, arraySize>::enqueue(const T& e)
{
    if(isFull()){
        throw QueueException("Desbordamiento de datos, tratando de encolar");
    }

    if(++endPos == arraySize){
        endPos=0;
    }

    data[endPos]=e;

    //data[endPos = (endPos == arraySize - 1) ? 0 :endPos + 1 ] = e ;
}

template <class T, int  arraySize>
T Cola<T, arraySize>::dequeue()
{
    if(isEmpty()){
        throw QueueException("Insuficiencia de datos, haciendo dequeue");
    }

    T r = data[frontPos++];

    if(frontPos == arraySize){
        frontPos=0;
    }

    return r;
}

template <class T, int  arraySize>
T Cola<T, arraySize>::getFront()
{

    if(isEmpty()){
        throw QueueException("Insuficiencia de datos, tratando de obtener el frente");
    }

    return data[frontPos];
}

#endif // COLA_H
