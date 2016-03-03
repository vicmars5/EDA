#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <string>
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
using namespace std;

template <class T, int arraySize=1024>
class List {
private:
    T data[arraySize];
    int last;
    bool isOrdered;
    bool isValidPos(int);
    int findDataLinear(const T&);
    int findDataBinary(const T&);
public:
    List(const List&);
    void initialize();

    bool isEmpty();
    bool isFull();

    void insertData(int, const T&);
    void deleteData(int);

    int getFirstPos();
    int getLastPos();
    int getPrevPos(int);
    int getNextPos(int);
    int findData(const T&);

    T retrieve(int);

    void sortData();

    void printData();

    void deleteAll();

};

template <class T, int arraySize>
bool List<T, arraySize>::isValidPos(int p) {
    return p >= 0 and p <=last;
}

//****

template <class T, int arraySize>
List<T, arraySize>::List(const List& l) {
    for (int i = 0; i <= l.last; i++){
        data[i] = l.data[i];
    }

    last=l.last;
    isOrdered=l.isOrdered;
}

template <class T, int arraySize>
void List<T, arraySize>::initialize() {
    last=-1;
}

template <class T, int arraySize>
bool List<T, arraySize>::isEmpty() {
    return last==-1;
}

template <class T, int arraySize>
bool List<T, arraySize>::isFull() {
    return last==arraySize-1;
}

template <class T, int arraySize>
void List<T, arraySize>::insertData(int p, const T& e) {
    if(isFull()) {
        throw ListException("La lista esta llena, tratando de insertar");
    }
    if(p !=-1 and !isValidPos(p)) {
        throw ListException("La posicion es invalida, tratando de insertar");
    }
    for(int i = last; i > p; i--) {
        data[i+1]=data[i];
    }
    data[p+1]=e;

    last++;
    isOrdered = false;
}

template <class T, int arraySize>
void List<T, arraySize>::deleteData(int p) {
    if(isEmpty()) {
        throw ListException("Insuficiencia de datos. La lista esta vacia, tratando de eliminar");
    }

    if(!isValidPos()) {
        throw ListException("Posicion invalida, tratando de eliminar");
    }

    for (int i=p; i<last;  i++) {
        data[i] = data[i + 1];
    }
}

template <class T, int arraySize>
int List<T, arraySize>::getFirstPos() {
    if(isEmpty()) {
        return -1;
    }
    return 0;
}

template <class T, int arraySize>
int List<T, arraySize>::getLastPos() {
    return last;
}

template <class T, int arraySize>
int List<T, arraySize>::getPrevPos(int p) {
    if(isEmpty() or !isValidPos(p) or p==0) {
        return -1;
    } else {
        return p-1;
    }

}

template <class T, int arraySize>
int List<T, arraySize>::getNextPos(int p) {
    if(isEmpty() or !isValidPos(p) or p==last-1) {
        return -1;
    }
    return p-1;
}

template <class T, int arraySize>
int List<T, arraySize>::findData(const T& e) {
    if(isOrdered) {
        return findDataBinary(e);
    }
    else {
        return findDataLinear(e);
    }
}


template <class T, int arraySize>
int List<T, arraySize>::findDataLinear(const T& e) {
    for (int i =0; i<=last; i++) {
        if(data[i]==e) {
            return i;
        }
    }
    return -1;
}

template <class T, int arraySize>
int List<T, arraySize>::findDataBinary(const T& e) {
    int i = 0;
    int j = last;

    while(i <= j) {
        m = (i + j) / 2;
        if(data[m] == e) {
            return m;
        }
        if(e < data[m]) {
            j = m -1;
        }
        else {
            i = m + 1;
        }
    }
    return -1;
}

template <class T, int arraySize>
T List<T, arraySize>::retrieve(int p) {
    if(isEmpty()) {
        throw ListException("Insuficiencia de datos, lista vacia al tratar de recuperar");
    }
    if(!isValidPos(p)) {
        throw ListException("Posicion invalida al tratar de recuperar");
    }
    return data[p];
}

int compare (const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}

template <class T, int arraySize>
void List<T, arraySize>::sortData() {
    qsort(data, last + 1, sizeof(T), compare);
    isOrdered = true;
}

template <class T, int arraySize>
void List<T, arraySize>::printData() {
    for(int i=0; i<=last; i++) {
        cout << data[i] << endl;
    }
}

template <class T, int arraySize>

void List<T, arraySize>::deleteAll() {
    last = -1;
}


#endif // LIST_H_INCLUDED
