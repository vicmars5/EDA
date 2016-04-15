#ifndef LIST_H
#define LIST_H

#include <exception>
#include <iostream>
#include <fstream>

#include "node.h"

using namespace std;

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

    void initialize();

    bool isEmpty();

    void insertData(Node <T>*, const T&);
    void deleteData(Node <T>*);

    Node<T>* getFirstPos();
    Node<T>* getLastPos();
    Node<T>* getPrevPos(Node<T>*);
    Node<T>* getNextPos(Node<T>*);
    Node<T>* findData(const T&);

    T& retrieve (Node<T>*);

    void printData();
    void deleteAll();

    void readFromDisk(const std::string&);
    void writeToDisk(const std::string&);
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
    } while(aux != nullptr);

    return false;
}

template <class T>
List<T>::List() {
    anchor = nullptr;
}

template <class T>
List<T>::~List() {
    deleteAll();
}

template <class T>
List<T>::List(const List<T>& l) : List(){
    Node<T>* aux = l.anchor;
    while(aux != nullptr) {
        insertData(getLastPos(), aux->getData());
        aux = aux->getNext();
    }
}

template <class T>
bool List<T>::isEmpty() {
    return anchor == nullptr;
}

template <class T>
void List<T>::insertData(Node <T>* p, const T& e) {
    if(!isValidPos(p) and p != nullptr) {
        throw ListException("Posición no valida al tratar de insertar");
    }

    Node<T>* aux = new Node<T>(e);
    if(aux ==nullptr) {
        throw ListException("Error, no hay espacio de memoria al tratar de insertar");
    }

    if(p == nullptr) {
        aux->setNext(anchor);
        if(anchor != nullptr) {
            aux->setNext(anchor);
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
        throw ListException("Error al eliminar, posicion no valida");
    }

    getPrevPos(p)->setNext(p->getNext());

    delete p;
}

template <class T>
Node<T>* List<T>::getFirstPos() {
    return anchor;
}

template <class T>
Node<T>* List<T>::getLastPos() {
    if(anchor == nullptr) {
        return nullptr;
    }

    Node<T>* aux = anchor;
    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
    }

    return aux;
}

template <class T>
Node<T>* List<T>::getPrevPos(Node<T>* p) {
    if(!isValidPos(p)) {
        return nullptr;
    }

    Node<T>* aux = anchor;
    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
        if(aux == p) {
            return aux;
        }
    }

    return nullptr;
}

template <class T>
Node<T>* List<T>::getNextPos(Node<T>* p) {
    if(!isValidPos(p)){
        return nullptr;
    }

    return p->getNext();
}

template <class T>
Node<T>* List<T>::findData(const T& p) {
    if(isEmpty()) {
        return nullptr;
    }

    Node<T>* aux= anchor;
    do{
        if(aux->getData() == p){
            return aux;
        }
        aux = aux->getNext();
    }while(aux == nullptr);

    return nullptr;
}

template <class T>
T& List<T>::retrieve(Node<T>* p) {
    if(!isValidPos(p)){
        throw ListException("Posicion no valida en RETRIEVE");
    }

    return p->getData();
}

template <class T>
void List<T>::printData() {
    if(isEmpty()){
        return;
    }

    Node<T>* aux = anchor;
    do{
        std::cout << aux->getData();
        aux = aux->getNext();
    }while(aux != nullptr);
}

template <class T>
void List<T>::deleteAll() {
    Node<T>* aux;

    while(anchor != nullptr) {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}

template <class T>
void List<T>::readFromDisk(const string& fileName){
    ifstream myFile;
    myFile.open(fileName.c_str(), ios_base::in);

    T d;

    if(!myFile.is_open()) {
        throw ListException("Error al LEER DE DISCO");
    }
    deleteAll();

    try {
        while(myFile >> d){
            insertData(getLastPos(), d);
        }
    } catch (ListException ex){
        ListException("Error al LEER DE DISCO");
    }
}

template <class T>
void List<T>::writeToDisk(const string& fileName){
    ofstream myFile;
    myFile.open(fileName.c_str(), ios_base::out);

    Node<T>* aux = anchor;

    if(isEmpty()) {
        throw ListException("Insuficiencia de datos al ESCRIBIR EN ARCHIVO");
    }

    if(myFile.is_open()) {
        do{
            myFile << aux->getData();

            aux = aux->getNext();
        } while(aux != nullptr);

        myFile.close();

    } else {
        throw ListException("Error de ESCRITURA EN DISCO, no se pudo abrir el archivo");
    }
}

#endif // LIST_H
