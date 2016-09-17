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

    void insertData(Node<T>*&, const T&);
    Node<T>* findData(Node<T>*&, const T&);

    void preorder(Node<T>*&);
    void inorder(Node<T>*&);
    void postorder(Node<T>*&);

    int balanceFactor(Node<T>*&);
    void doBalancing(Node<T>*&);

    void doLeftSimpleRotation(Node<T>*&);
    void doRightSimpleRotation(Node<T>*&);

    void doLeftDoubleRotation(Node<T>*&);
    void doRightDoubleRotation(Node<T>*&);

    unsigned int getHeight(Node<T>*&);

    void deleteAll(Node<T>*&);
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
    unsigned int getLeftHeight();
    unsigned int getRightHeight();

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
    deleteAll();
}

template <class T>
void BinaryTree<T>::insertData(const T& e) {
    insertData(root, e);
}

template <class T>
void BinaryTree<T>::insertData(Node<T>*& r, const T& e) {
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
        doBalancing(r);
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
unsigned int BinaryTree<T>::getHeight() {
    return getHeight(root);
}

template <class T>
unsigned int BinaryTree<T>::getHeight(Node<T>*& r) {
    unsigned int heightLeft, heightRight;
    if(r == nullptr) {
        return 0;
    }
    heightLeft = getHeight(r->getLeft());
    heightRight = getHeight(r->getRight());

    if(heightLeft > heightRight) {
        return heightLeft + 1;
    } else {
        return heightRight + 1;
    }
}


template <class T>
unsigned int BinaryTree<T>::getLeftHeight() {
    return getHeight(root->getLeft());
}

template <class T>
unsigned int BinaryTree<T>::getRightHeight() {
    return getHeight(root->getRight());
}

template <class T>
bool BinaryTree<T>::isEmpty() {
    return root == nullptr;
}

template <class T>
void BinaryTree<T>::deleteData(Node<T>*& r) {
    if(r==nullptr) {
        return;
    }
    if(isLeaf(r)) {
        delete r;
        r = nullptr;
    } else {
        Node<T>*& aux = r->getLeft() != nullptr ?
                        getHighest(r->getLeft()) : getLowest(r->getRight());
        r->setData(aux->getData());
        deleteData(aux);
    }
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
    if(r == nullptr or r->getLeft() == nullptr) {
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
void BinaryTree<T>::preorder(Node<T>*& r) {
    if(r == nullptr) {
        return;
    }
    cout << r->getData() << ", ";
    preorder(r->getLeft());
    preorder(r->getRight());
}

template <class T>
void BinaryTree<T>::inorder() {
    inorder(root);
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
void BinaryTree<T>::postorder() {
    postorder(root);
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
bool BinaryTree<T>::isLeaf(Node<T>*& r) {
    return r->getLeft() == nullptr and r->getRight() == nullptr;
}

template <class T>
bool BinaryTree<T>::isFather(Node<T>*& r) {
    return r->getLeft() != nullptr or r->getRight() != nullptr;
}

template <class T>
void BinaryTree<T>::deleteAll() {
    deleteAll(root);
    root = nullptr;
}

template <class T>
void BinaryTree<T>::deleteAll(Node<T>*& r) {
    if(r == nullptr) {
        return;
    }
    deleteAll(r->getLeft());
    deleteAll(r->getRight());
    delete r;

    r = nullptr;
}

template <class T>
int BinaryTree<T>::balanceFactor(Node<T>*& r) {
    if(r == nullptr) {
        return 0;
    }
    return getHeight(r->getRight()) - getHeight(r->getLeft());
}

template <class T>
void BinaryTree<T>::doBalancing(Node<T>*& r) {
    switch(balanceFactor(r)) {
    case 2: /// En caso que este desbalanaceado a al derecha
        if(balanceFactor(r->getRight()) == 1) {
            doLeftSimpleRotation(r);
        } else {
            doLeftDoubleRotation(r);
        }
        break;
    case -2: /// En caso de que este desbalanceado hacia la izquierda
        if(balanceFactor(r->getLeft()) == -1) {
            doRightSimpleRotation(r);
        } else {
            doRightDoubleRotation(r);
        }
        break;
    }
}

template <class T>
void BinaryTree<T>::doLeftSimpleRotation(Node<T>*& r) {
    Node<T>* aux1 = r->getRight();
    Node<T>* aux2 = aux1->getLeft();

    r->setRight(aux2);
    aux1->setLeft(r);
    r = aux1;

}

template <class T>
void BinaryTree<T>::doRightSimpleRotation(Node<T>*& r) {
    Node<T>* aux1 = r->getLeft();
    Node<T>*  aux2 = aux1->getRight();

    r->setLeft(aux2);
    aux1->setRight(r);
    r = aux1;
}

template <class T>
void BinaryTree<T>::doLeftDoubleRotation(Node<T>*& r) {
    doRightSimpleRotation(r->getRight());
    doLeftSimpleRotation(r);
}

template <class T>
void BinaryTree<T>::doRightDoubleRotation(Node<T>*& r) {
    doLeftSimpleRotation(r->getLeft());
    doRightSimpleRotation(r);
}



#endif // BINARYTREE_H
