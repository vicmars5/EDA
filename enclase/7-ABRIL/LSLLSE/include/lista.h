#ifndef LISTA_H
#define LISTA_H

#include "node.h"

#include <iostream>
#include <exception>

class ListException : public std::exception {
private:
    std::string msg;
public:
    explicit ListException(const char* message) : msg(message) {}
    explicit ListException(const std::string& message) :msg(message) {}
    virtual ~ListException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T>
class List {
private:
    Node<T>* header;
    unsigned counter;

    bool isValidPos(Node<T>*);

public:
    List();
    List(const List<T> &);
    ~List();

    bool isEmpty();

    void insertData(Node <T>*, const T&);
    void deleteData(Node <T>*);

    Node<T>* getFirstPos();
    Node<T>* getLastPos();
    Node<T>* getPrevPos(Node<T>*);
    Node<T>* getNextPos(Node<T>*);
    Node<T>* findData(const T*);

    T& retrieve (Node<T>*);

    void printData();
    void deleteAll();

};

template <class T>
bool List<T>::isValidPos(Node<T>* p) {
    if(isEmpty()) {
        return false;
    }

    Node<T>* aux = anchor;

    do {
        if(aux == p) {
            return true;
        }

        aux = aux->getNext();
    } while (aux != anchor);

    return false;
}

template <class T>
List<T>::List() {
    header = new Node(T);

    if(header == nullptr) {
        throw ListException("Memoria no disponible al iniciar lista");
    }

    header->setPrev(header);
    header->setNext(header);

    counter = 0;
}

//Revisar constructor copia
template <class T>
List<T>::List(const List<T>& l) : List() {
    Node<T>* aux = l.header->getNext();
    do{
        insertData(getLastPos(), aux->getData());

        aux = aux->getNext();
    }while();///pendiente
}

///Destructor llama a delete

template <class T>
List<T>::~List() {
    deleteAll();
    delete header;
}

template <class T>
bool List<T>::isEmpty() {
    return header->getNext == header;
}

template <class T>
void List<T>::insertData(Node <T>* p, const T& e) {
    if (!isValidPos(p) and p != nullptr) {
        throw ListException("Posicion invalida al tratar de insertar");
    }

    Node<T>* aux;

    try{
        new Node<T>(e);
    } catch(NodeException ex) {
        throw ListException(ex.what());
    }

    if(aux == nullptr) {
        throw ListException("Memoria insuficiente al tratar de insertar");
    }

    if(p == nullptr) {
        p = header;
    }

    aux->setPrev(p);
    aux->setNext(P->getNext());

    p->getNext()->setPrev(aux);
    p->setNext(aux);

    counter++;
}

template <class T>
void List<T>::deleteData(Node <T>* p) {
    if(!isValidPos(p)) {
        throw ListException("POsicion no valida");
    }

    p->getPrev()->setNext(p->getNext());
    p->getNext()->setNext(p->getPrev());

    delete p;
    counter--;
}

template <class T>
Node<T>* List<T>::getFirstPos() {
    if (isEmpty) {
        return nullptr;
    } else {
        return header->getPrev();
    }
}

///Revisar
template <class T>
Node<T>* List<T>::getLastPos() {
    if (isEmpty()) {
        return nullptr;
    }

    return anchor->getPrev();
}

template <class T>
Node<T>* List<T>::getPrevPos(Node<T>* p) {
    if(!isValidPos(p) or p == getFirstPos) {
        return nullptr;
    }

    return p->getPrev();
}

template <class T>
Node<T>* List<T>::getNextPos(Node<T>* p) {
    if(!isValidPos(p) or p == getLastPos()) {
        return nullptr;
    }

    return p->getNext();
}

template <class T>
Node<T>* List<T>::findData(const T* e) {
    //Igual que en la circular - Revisar
    if(isEmpty()) {
        return nullptr;
    }

    Node<T> aux = header->getNext;

    while (aux != header) {
        if(aux->getData() == e) {
            return aux;
        }

        aux =  aux->getNext();
    }

    return nullptr;
}

template <class T>
T& List<T>::retrieve(Node<T>* p) {
    if(!isValidPos(p)) {
        throw ListException("Posicion invalida al hacer retrieve");
    }

    return p->getData();
}

template <class T>
void List<T>::printData() {
    if (isEmpty()){
        return;
    }

    Node<T>* aux = header->getNext();
    do{
        std::cout << aux->getData() << ", ";
        aux = aux->getNext();
    } while (aux != header);
}

template <class T>
void List<T>::deleteAll() {
    if (isEmpty()) {
        return;
    }

    Node<T>* aux;

    while (header->getNext != header) {
        aux = header->getNext;
        header->setNext(header->getNext()->getNext());
        delete aux;
    }

    header->setNext(header);
    header->setPrev(header);

    counter = 0;
}

#endif // LISTA_H
