#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <exception>
#include <string>
#include <iostream>

#include "node.h"

using namespace std;

class BinaryTreeException : public std::exception {
private:
    std::string msg;
public:
    explicit BinaryTreeException(const char* message) : msg(message) {}
    explicit BinaryTreeException(const std::string& message) :msg(message) {}
    virtual ~BinaryTreeException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T>
class BinaryTree {

private:
    Node<T>* root; //Raíz

    void insertData(Node<T>*, const T&);
    Node<T>* findData(Node<T>*&, const T&);

    void preorder(Node<T>*&);
    void inorder(Node<T>*&);
    void postorder(Node<T>*&);

    unsigned int getHeight(Node<T>*&);
public:
    BinaryTree();
    virtual ~BinaryTree();

    bool isEmpty();

    void insertData(const T&);
    void deleteData(Node<T>*&);

    Node<T>* findData(const T&);
    T& retrieve(Node<T>*&);

    Node<T>* getLowest(Node<T>*&);
    Node<T>* getHighest(Node<T>*&);

    void preorder();
    void inorder();
    void postorder();

    unsigned int getHeight();
    bool isLeaf(Node<T>*&);
    bool isFather(Node<T>*&);

    void deleteAll();
};


template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    cout << root->getData() << endl;
    deleteAll();
}

template <class T>
void BinaryTree<T>::insertData(const T& e) {
    insertData(root, e);
}

template <class T>
void BinaryTree<T>::insertData(Node<T>* r, const T& e) {
    if(r == nullptr) {
        try {
            r = new Node<T>(e);
        } catch (NodeException ex) {
            throw BinaryTreeException("ERROR INSERTANDO DATOS");
        }
        if(r == nullptr) {
            throw BinaryTreeException("ERROR, NO SE PUDO RESERVAR ESPACIO DE MEMORIA");
        }
    } else {
        if(e < r->getData()) {
            insertData(r->getLeft(), e);
        } else {
            insertData(r->getRight(), e);
        }
    }
}

template <class T>
Node<T>* BinaryTree<T>::findData(Node<T>*& r, const T& e) {
    if(r == nullptr) {
        return nullptr;
    }
    if(r->getData() == e) {
        return r;
    }
    if(e < r->getData()) {
        return findData(r->getLeft(), e);
    } else {
        return findData(r->getRight(), e);
    }
}

template <class T>
unsigned int BinaryTree<T>::getHeight(Node<T>*&) {

}

template <class T>
bool BinaryTree<T>::isEmpty() {
    return root == nullptr;
}

template <class T>
void BinaryTree<T>::deleteData(Node<T>*&) {

}

template <class T>
Node<T>* BinaryTree<T>::findData(const T& e) {
    return findData(root, e);
}

template <class T>
T& BinaryTree<T>::retrieve(Node<T>*& r) {
    if(r == nullptr) {
        throw BinaryTreeException("ERROR AL HACER RETRIEVE");
    }
    return r->getData();
}

template <class T>
Node<T>* BinaryTree<T>::getLowest(Node<T>*& r) {
    if(r == nullptr or r->getLeft() == nullptr){
        return r;
    }
    return getLowest(r->getLeft());
}

template <class T>
Node<T>* BinaryTree<T>::getHighest(Node<T>*& r) {
    if (r == nullptr or r->getRight() == nullptr) {
        return r;
    }
    return getHighest(r->getRight());
}

template <class T>
void BinaryTree<T>::preorder() {
    preorder(root);
}

template <class T>
void BinaryTree<T>::inorder() {
    inorder(root);
}

template <class T>
void BinaryTree<T>::postorder() {
    postorder(root);
}

template <class T>
void BinaryTree<T>::preorder(Node<T>*& r) {
    if(r == nullptr) {
        return;
    }
    cout << r->getData() << ", ";
    preorder(r->getLeft());
    preorder(r->getRight());
}

template <class T>
void BinaryTree<T>::inorder(Node<T>*& r) {
    if (r == nullptr) {
        return;
    }

    inorder(r->getLeft());
    cout << r->getData() << ", ";
    inorder(r->getRight());
}

template <class T>
void BinaryTree<T>::postorder(Node<T>*& r) {
    if (r == nullptr) {
        return;
    }

    postorder(r->getLeft());
    postorder(r->getRight());
    cout << r->getData() << ", ";

}

template <class T>
unsigned int BinaryTree<T>::getHeight() {
    return getHeight(root);
}

template <class T>
bool BinaryTree<T>::isLeaf(Node<T>*& r) {
}

template <class T>
bool BinaryTree<T>::isFather(Node<T>*&) {

}

template <class T>
void BinaryTree<T>::deleteAll() {

}


#endif // BINARYTREE_H
