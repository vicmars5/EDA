#ifndef PRODUCT_H
#define PRODUCT_H
#include <date.h>

using namespace std;

struct Product {
    string name;
    string barCode;
    float weight;
    Date enterDate;
    float wholesalePrice;
    float retailPrice;
    int stock;
    };

#endif // PRODUCT_H
