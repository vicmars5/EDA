#ifndef NODE_H
#define NODE_H

#include <exception>
#include <string>

using namespace std;

class NodeException : public std::exception {
private:
    std::string msg;
public:
    explicit NodeException(const char* message) : msg(message) {}
    explicit NodeException(const std::string& message) :msg(message) {}
    virtual ~NodeException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T>
class Node {
public:
    Node();
    Node(const T&);
    ~Node();

    T& getData();
    T* getDataPtr();

    Node<T>*& getLeft();
    Node<T>*& getRight();

    void setData(const T&);
    void setDataPtr(T*);

    void setLeft(Node<T>*&);
    void setRight(Node<T>*&);
private:
    T* dataPtr;
    Node<T>* left;
    Node<T>* right;
};

template <class T>
Node<T>::Node() {
    left = nullptr;
    right = nullptr;
    dataPtr = nullptr;
}

template <class T>
Node<T>::Node(const T& e) : Node() {
    dataPtr = new T(e);

    if(dataPtr == nullptr) {
        throw NodeException("Memoria no disponible al crear nodo");
    }
}

template <class T>
Node<T>::~Node() {
    delete dataPtr;
}

template <class T>
T& Node<T>::getData() {
    return *dataPtr;
}

template <class T>
T* Node<T>::getDataPtr() {
    return dataPtr;
}

template <class T>
Node<T>*& Node<T>::getLeft() {
    return left;
}

template <class T>
Node<T>*& Node<T>::getRight() {
    return right;
}

template <class T>
void Node<T>::setData(const T& e) {
    if(dataPtr == nullptr) {
        dataPtr = new T(e);
        if(dataPtr == nullptr) {
            NodeException("Error en SET DATA");
        }
        return;
    }

    *dataPtr = e;
}

template <class T>
void Node<T>::setDataPtr(T* ptr) {
    dataPtr = ptr;
}

template <class T>
void Node<T>::setLeft(Node<T>*& ptr) {
    left = ptr;
}

template <class T>
void Node<T>::setRight(Node<T>*& ptr) {
    right = ptr;
}

#endif // NODE_H
