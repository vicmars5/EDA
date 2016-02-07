#include "productsCollection.h"

bool ProductsCollection::isValidPos(int p)
{
    return p >= 0 and p <= last;
}

void ProductsCollection::initialize()
{
    last = -1;
}

bool ProductsCollection::isEmpty()
{
    return last == -1;
}

bool ProductsCollection::isFull()
{
    return last == ARRAY_SIZE - 1;
}

void ProductsCollection::insertData(int p, const Product& prod)
{
    if(isFull()){
        throw ProductsCollectionException("The list is full, trying to insert");
    }
    if(p !=-1 and !isValidPos(p)){
        throw ProductsCollectionException("Invalid position, trying to insert");
    }
    for(int i = last; i > p; i--){
        data[i+1] = data[i];
    }

    data[p+1] = prod;

    last++;

}

void ProductsCollection::deleteData(int p)
{
    if(isEmpty()){
        throw ProductsCollectionException("DATA UNDERRUN. The list is empty, trying to delete");
    }
    if(!isValidPos(p)){
        throw ProductsCollectionException("INVALID POSITION, trying ot delete");
    }
    for (int i=p; i < last; i++){
        data[i] = data[i + 1];
    }
    last--;
}

int ProductsCollection::getFirstPos()
{
    if(isEmpty()){
        return -1;
    }
    return 0;
}

int ProductsCollection::getLastPos()
{
    return last;
}

int ProductsCollection::getPrevPos(int p)
{
    if(isEmpty() or !isValidPos(p) or p==0){
        return -1;
    }
    else{
        return p-1;
    }
}

int ProductsCollection::getNextPos(int p)
{
    if(isEmpty() or !isValidPos(p) or p == last - 1){
        return -1;
    }
    return p-1;
}

int ProductsCollection::findData(const string& prod) {
    for(int i = 0; i <= last;  i++) {
        if(data[i].barCode == prod) {
            return i;
            }
        }
    return -1;
    }

Product ProductsCollection::retrieve(int p)
{
    if(isEmpty()){
        throw ProductsCollectionException("DATA UNDERRUN, list empty, trying to get data");
    }
    if(!isValidPos(p)){
        throw ProductsCollectionException("INVALID POSITION, trying to get data");
    }
    return data[p];
}

void ProductsCollection::sortData()
{

}

void ProductsCollection::printData()
{

}

void ProductsCollection::deleteAll()
{
    last=-1;
}
