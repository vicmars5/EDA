#ifndef COLA_H
#define COLA_H

#include <exception>

class ColaException : public std::exception {
private:
    std::string msg;
public:
    explicit ColaException(const char* message) : msg(message) {}
    explicit ColaException(const std::string& message) :msg(message) {}
    virtual ~ColaException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T, int arraySize=1024>
class Cola {
public:
    Cola();
    void inicializa();

    bool estaVacia();
    bool estaLlena();

    void agregar(const T&);
    T obtenerFrente(); //Top

    void eliminar();
    void imprimir();
protected:
    int frente;
    int fin;
    T datos[arraySize];
private:
};

template <class T, int arraySize>
Cola<T, arraySize>::Cola() {
    frente = 0;
    fin = arraySize - 1;
}

template <class T, int arraySize>
void Cola<T, arraySize>::inicializa() {
    frente = 0;
    fin = arraySize - 1;
}

template <class T, int arraySize>
bool Cola<T, arraySize>::estaVacia() {
    return frente == (fin + 1) or
           (frente == 0 and fin == (arraySize - 1));
}

template <class T, int arraySize>
bool Cola<T, arraySize>::estaLlena() {
    return frente == (fin + 2) or
           (frente == 0 and fin == (arraySize - 2)) or
           (frente == 1 and fin == (arraySize - 1));
}

template <class T, int arraySize>
void Cola<T, arraySize>::agregar(const T& elem) {
    if(estaLlena()) {
        throw ColaException("ERROR, Desbordamiento de datos");
    } else {
        fin++;
        if(fin == arraySize) {
            fin = 0;
        }
        datos[fin] = elem;
    }
}

template <class T, int arraySize>
void Cola<T, arraySize>::eliminar() {
    if(estaVacia()) {
        throw ColaException("ERROR, Insuficiencia de datos");
    } else {
        frente++;
        if(frente == arraySize) {
            frente = 0;
        }
    }
}

template <class T, int arraySize>
T Cola<T, arraySize>::obtenerFrente() {
    if(estaVacia()) {
        throw ColaException("ERROR, Insuficiencia de datos");
    } else {
        return datos[frente];
    }
}


#endif // COLA_H
