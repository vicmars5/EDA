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
    Node<T>* anchor;

    bool isValidPos(Node<T>*);
public:
    List();
    ~List();
    List(const List<T> &);

    bool isEmpty();

    void insertData(Node <T>*, const T&);
    void deleteData(Node <T>*);

    Node<T>* getFirstPos();
    Node<T>* getLastPos();
    Node<T>* getPrevPos(Node<T>*);
    Node<T>* getNextPos(Node<T>*);
    Node<T>* findData(const T*);

    T& retrieve (Node<T> * );

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
    anchor = nullptr;
}

template <class T>
List<T>::List(const List<T>& l) : List() {
    if(l.isEmpty()) {
        return;
    }
    Node<T>* aux = l.anchor;

    do {
        insertData(getLastPos(), aux->getData());

        aux = aux->getNext();
    } while (aux != l.anchor);
}

///Destructor llama a delete

template <class T>
bool List<T>::isEmpty() {
    return anchor == nullptr;
}

template <class T>
void List<T>::insertData(Node <T>* p, const T& e) {
    if (!isValidPos(p) and p != nullptr) {
        throw ListException("Posicion invalida");
    }

    Node<T>* aux = new Node<T>(e);
    if(aux == nullptr) {
        throw ListException("Memoria insuficiente al tratar de insertar");
    }

    if(p == nullptr) {
        if (!isEmpty()) {
            aux->setNext(aux);
        } else {
            aux->setNext(anchor);
            getLastPos()->setNext(aux);
        }
        anchor = aux;
    } else {
        aux->setNext(p->getNext());
        p->setNext(aux);
    }
}

template <class T>
void List<T>::deleteData(Node <T>* p) {
    if(!isValidPos(p)) {
        throw ListException("POsicion no valida");
    }

    if(p == anchor) {
        if(p->getNext() == p) {
            anchor = nullptr;
        } else {
            getLastPos()->setNext(anchor = anchor->getNext());
        }
    } else {
        getPrevPos(p)->setNext(p->getNext());
    }

    delete p;
}

template <class T>
Node<T>* List<T>::getFirstPos() {
    return anchor;
}

template <class T>
Node<T>* List<T>::getLastPos() {
    if (isEmpty()) {
        return nullptr;
    }

    Node<T>* aux = anchor;

    while (aux->getNext() != anchor) {
        aux = aux->getNext();
    }

    return aux;
}

template <class T>
Node<T>* List<T>::getPrevPos(Node<T>* p) {
    if(isEmpty() or p == anchor) {
        return nullptr;
    }

    Node<T>* aux = anchor;

    while(aux != anchor) {
        if(aux->getNext() == p) {
            return aux;
        }

        aux = aux->getNext();
    }

    return nullptr;
}

template <class T>
Node<T>* List<T>::getNextPos(Node<T>* p) {
    if(!isValidPos(p)) {
        return nullptr;
    }

    if(p->getNext() == anchor) {
        return nullptr;
    }

    return p->getNext();
}

template <class T>
Node<T>* List<T>::findData(const T* e) {
    if(isEmpty()) {
        return nullptr;
    }

    Node<T> aux = anchor;

    do {
        if(aux->getData() == e) {
            return aux;
        }

        aux =  aux->getNext();
    } while (aux != anchor);

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

    Node<T>* aux = anchor;
    do{
        std::cout << aux->getData();
        aux = aux->getNext();
    } while (aux != anchor);
}

template <class T>
void List<T>::deleteAll() {
    if (isEmpty()) {
        return;
    }

    Node<T>* aux;
    Node<T>* mark = anchor;

    do {

        aux = anchor;
        anchor =  anchor->getNext();

        delete aux;
    } while (anchor != mark);
}




#endif // LISTA_H
