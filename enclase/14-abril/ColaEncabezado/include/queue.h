#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
    public:
        Queue() {}
        ~Queue() {}

        Queue(const Queue&);

        bool isEmpty();

        void enqueue(const T&);
        T& dequeue();

        T& getFront();
    protected:
        T* header;
    private:
};

Queue::Queue(const Queue& q) : Queue()
{
    if(q.isEmpty) {
        return;
    }

    Node<T>* aux = q.header->getNext();
    ///Revisar
}

Queue::~Queue() {
}

bool Queue::isEmpty()
{
    return header == header->getNext;
}

void Queue::enqueue(const T&)
{
    Node<T> aux*;
    try{
        aux = new Node<T>(e);
    } catch (NodeException ex) {
        throw QueueException(ex.what());
    }

    if(aux == nullptr) {
        QueueException("Memoria insuficiente al hacer enqueue");
    }

    aux->setPrev(header->getPrev());
    aux->setNext(header);

    header->getPrev()->setNext(aux);
    header->setPrev(aux);
}

T Queue::dequeue()
{
    if(isEmpty()) {
        QueueException("Insuficiencia de datos al hacer DEQUEUE");
    }

    T r(header->getNext()->getData());

    Node<T>* aux = header->getNext();

    header->getNext()->getNext()->setPrev(header);
    header->setNext(header->getNext()->getNext());

    delete aux;

    return r;
}

T Queue::getFront()
{
    if(isEmpty()) {
        throw QueueException("Insuficiencia de datos haciendo el dequeue");
    }

    return header->getNext()->getData();
}




#endif // QUEUE_H
