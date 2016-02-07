#ifndef MENU_H
#define MENU_H

#include "productsCollection.h"

class Menu {
    public:
        Menu();
        virtual ~Menu();
        void showMenu();
        ProductsCollection pCollection;
    protected:
        void addProduct();
        void getProduct();
        void addProductStock();
    private:
    };

#endif // MENU_H
