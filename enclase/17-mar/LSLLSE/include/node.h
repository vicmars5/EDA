#ifndef NODE_H
#define NODE_H

template <class T>
class Node {

public:
    Node();
    Node(const T&);

    T& getData();
    Node <T>* getPrev();
    Node<T>* getNext();

    void setData(const T&);
    void setPrev(Node<T>*);
    void setNext(Node<T>*);

private:
    T data;
    Node<T>* prev;
    Node<T>* next;
};

template <class T>
Node<T>::Node() {
    prev = next = nullptr;
}

template <class T>
Node<T>::Node(const T& e) : Node(){
    data = e;
}

template <class T>
T& Node<T>::getData() {
    return data;
}

template <class T>
Node<T>* Node<T>::getPrev() {
    return prev;
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
void Node<T>::setPrev(Node<T>* p) {
    prev = p;
}

template <class T>
void Node<T>::setNext(Node<T>* p) {
    next = p;
}

#endif // NODE_H
