#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED


class NodeException : public std::exception {
    private:
        std:: string msg;

    public:
        explicit NodeException(const char* message) : msg(message) {}
        explicit NodeException(const std::string& message) : msg(message) {}
        virtual ~NodeException() throw() {}
        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

template <class T>
class Node {
    private:
        T dataPtr;
        Node* left;
        Node* right;

    public:
        Node();
        Node(const T&);
        ~Node();

        T& getData();
        T* getDataPtr();
        Node<T>*& getLeft();
        Node<T>*& getRight();

        void setData(const T&);
        void setDataPtr (T*);
        void setLeft(Node<T>*);
        void setRight(Node<T>*);
    };

template <class T>
Node<T>::Node() {
    right = left = nullptr;
    dataPtr = nullptr;
    }

template <class T>
Node<T>::Node(const T& e) : Node() {
    dataPtr = new T(e);

    if (dataPtr == nullptr) {
        throw NodeException("Memoria no disponible al crear nodo :v");
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
Node<T>*& Node<T>::getLeft() {
    return left;
    }

template <class T>
Node<T>*& Node<T>::getRight() {
    return right;
    }

template <class T>
void Node<T>::setData(const T& e) {
    if (dataPtr == nullptr){
        dataPtr = new T(e);
        if (dataPtr == nullptr){
            throw NodeException("Memoria no disponible al colocar dato en nodo");
        }
    }
    *dataPtr = e;
    }

template <class T>
void Node<T>::setLeft(Node<T>* p) {
    left = p;
    }

template <class T>
void Node<T>::setRight(Node<T>* p) {
    right = p;
    }

template <class T>
void Node<T>::setDataPtr(T* p) {
    dataPtr = p;
    }
#endif // NODE_H_INCLUDED
