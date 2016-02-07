#ifndef PRODUCTSCOLLECTION_H
#define PRODUCTSCOLLECTION_H
#define ARRAY_SIZE 1024
#include "product.h"


class ProductsCollectionException : public std::exception {
    private:
        std::string msg;
    public:
        explicit ProductsCollectionException(const char* message) : msg(message) {}
        explicit ProductsCollectionException(const std::string& message) :msg(message) {}
        virtual ~ProductsCollectionException() throw () {}
        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

class ProductsCollection {
    private:
        Product data[ARRAY_SIZE];
        int last;
        bool isValidPos(int);
    public:
        void initialize();

        bool isEmpty();
        bool isFull();

        void insertData(int, const Product&);
        void deleteData(int);

        int getFirstPos();
        int getLastPos();
        int getPrevPos(int);
        int getNextPos(int);
        int findData(const string&);

        Product retrieve(int);

        void sortData();

        void printData();

        void deleteAll();
    };

#endif // PRODUCTSCOLLECTION_H
