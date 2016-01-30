#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz{
    public:
        Matriz();
        virtual ~Matriz();
        void crearMatrices();

    protected:
    private:
        double matriz[3][10][10];
        int tam;
        void mostrarMatrices();
        void multiplicarMatrices();
};

#endif // MATRIZ_H
