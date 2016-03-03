#ifndef PILA_H
#define PILA_H

#include <exception>

class PilaException : public std::exception {
private:
    std::string msg;
public:
    explicit PilaException(const char* message) : msg(message) {}
    explicit PilaException(const std::string& message) :msg(message) {}
    virtual ~PilaException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T, int arraySize=1024>
class Pila {
public:
    Pila();
    void inicializa();

    bool estaVacia();
    bool estaLlena();

    void apilar(const T&);
    T tope(); //Top

    void desapilar();

protected:
    T datos[arraySize];
    int ultimo;

private:
};

template <class T, int arraySize>
Pila<T, arraySize>::Pila() {
    ultimo=-1;
}

template <class T, int arraySize>
void Pila<T, arraySize>::inicializa() {
    ultimo=-1;
}

template <class T, int arraySize>
bool Pila<T, arraySize>::estaVacia() {
    return ultimo == -1;
}

template <class T, int arraySize>
bool Pila<T, arraySize>::estaLlena() {
    return ultimo == (arraySize - 1);
}

template <class T, int arraySize>
void Pila<T, arraySize>::apilar(const T& elem) {
    if(estaLlena()) {
        throw PilaException("ERROR, Desbordamiento de datos");
    } else {
        ultimo++;
        datos[ultimo]=elem;
    }
}
template <class T, int arraySize>
void Pila<T, arraySize>::desapilar() {
    if(estaLlena()) {
        throw PilaException("ERROR, Insuficiencia de datos");
    } else {
        ultimo--;
    }
}

template <class T, int arraySize>
T Pila<T, arraySize>::tope() {
    if(estaVacia()) {
        throw PilaException("ERROR, insuficiencia de datos");
    } else {
        return datos[ultimo];
    }
}



#endif // PILA_H
