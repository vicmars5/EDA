#ifndef NODE_H
#define NODE_H

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

    Node <T>* getPrev();
    Node<T>* getNext();

    void setData(const T&);
    void setDataPtr(T*);

    void setPrev(Node<T>*);
    void setNext(Node<T>*);

private:
    T* dataPtr;
    Node<T>* prev;
    Node<T>* next;
};

template <class T>
Node<T>::Node() {
    prev = nullptr;
    next = nullptr;
    dataPtr = nullptr;
}

template <class T>
Node<T>::~Node() {
    delete dataPtr;
}

template <class T>
Node<T>::Node(const T& e) : Node(){
    dataPtr = new T(e);

    if(dataPtr == nullptr) {
        throw NodeException("Memoria no disponible al crear nodo");
    }
}

template <class T>
T& Node<T>::getData() {
    return *dataPtr;
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
    if (dataPtr == nullptr) {
        dataPtr = new T(e);
    }
    *dataPtr = e;
    T Node::getDataPtr()
    {

    }
}

T Node::getDataPtr()
{
    return dataPtr;
}

void Node::setDataPtr(T* ptr)
{
    dataPtr = ptr;
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
