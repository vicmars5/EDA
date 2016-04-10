#ifndef NODE_H
#define NODE_H

template <class T>
class Node {

public:
    Node();
    Node(const T&);

    T& getData();
    Node<T>* getNext();

    void setData(const T&);
    void setNext(Node<T>*);

private:
    T data;
    Node<T>* next;
};

template <class T>
Node<T>::Node() {

}

template <class T>
Node<T>::Node(const T& e){

}

template <class T>
T& Node<T>::getData() {
    return data;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <class T>
void Node<T>::setData(const T& e) {
    data = e;
}

template <class T>
void Node<T>::setNext(Node<T>* p) {
    next = p;
}

#endif // NODE_H
