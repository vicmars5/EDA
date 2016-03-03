#include "songsList.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool SongsList::isValidPos(int p) {
    return p >= 0 and p <=last;
}

void SongsList::initialize() {
    last=-1;
}

bool SongsList::isEmpty() {
    return last==-1;
}

bool SongsList::isFull() {
    return last==ARRAY_SIZE-1;
}

void SongsList::insertData(int p, const Song& song) {
    if(isFull()) {
        throw SongsListException("The list is full, trying to insert");
    }
    if(p != -1 and !isValidPos(p)) {
        throw SongsListException("Invalid position, trying to insert");
    }
    for(int i = last; i > p; i--) {
        data[i + 1] = data[i];
    }
    data[p + 1] = song;
    last++;
}

void SongsList::deleteData(int p) {
    if(isEmpty()) {
        throw SongsListException("DATA UNDERRUN. The list is empty, trying to delete");
    }
    if(!isValidPos(p)) {
        throw SongsListException("INVALID POSITION, trying ot delete");
    }
    for(int i = p; i < last; i++) {
        data[i] = data[i + 1];
    }
    last--;
}

int SongsList::getFirstPos() {
    if(isEmpty()) {
        return -1;
    }
    return 0;
}

int SongsList::getLastPos() {
    return last;
}

int SongsList::getPrevPos(int p) {
    if(isEmpty() or !isValidPos(p) or p == 0) {
        return -1;
    }
    return p-1;
}

int SongsList::getNextPos(int p) {
    if(isEmpty() or !isValidPos(p) or p == last - 1) {
        return -1;
    }
    return p-1;
}

int SongsList::findData(const string& name) {
    for(int i = 0; i <= last; i++) {
        if(data[i].name == name) {
            return i;
        }
    }
    return -1;
}

Song SongsList::retrieve(int p) {
    if(isEmpty()) {
        throw SongsListException("DATA UNDERRUN, list empty, trying to get data");
    }
    if(!isValidPos(p)) {
        throw SongsListException("INVALID POSITION, trying to get data");
    }
    return data[p];
}

void SongsList::sortData() {

}

void SongsList::printData() {
    int i;
    cout << "Canciones: " << endl;
    for (i = 0; i <= last; i++) {
        cout << "Nombre " << data[i].name << endl
             << "Autor " << data[i].author << endl
             << "Interprete " << data[i].player << endl
             << "Ranking " << data[i].ranking << endl << endl;
    }
    if(i==0) {
        cout << "No hay canciones en el ranking" << endl;
    }
    cout << endl;
}

void SongsList::deleteAll() {
    last=-1;
}

void SongsList::writeToDisk(const string nombreArchivo) {
    ofstream miArchivo;
    miArchivo.open(nombreArchivo.c_str(), ios_base::out);
    if(miArchivo.is_open()) {
        for(int i = 0; i < last; i++) {
            miArchivo << data[i].name << endl
                      << data[i].author << endl
                      << data[i].player << endl
                      << data[i].ranking << endl;
        }
        miArchivo.close();
    } else {
        throw SongsListException("Error de escritura al disco");
    }
}

void SongsList::readFromDisk(string nombreArchivo) {
    ifstream miArchivo;
    miArchivo.open(nombreArchivo.c_str(), ios_base::in);
    string miString;
    if (!miArchivo.is_open()) {
        throw SongsListException("Error de lectura de disco");
    }

    deleteAll();

    try {
        Song s;
        while(getline(miArchivo, miString)) {
            s.name = miString;
            if(getline(miArchivo, miString)) {
                s.author = miString;
                if(getline(miArchivo, miString)) {
                    s.player = miString;
                    if(getline(miArchivo, miString)) {
                        s.ranking = atoi(miString.c_str());
                    }
                }
            }
            insertData(getLastPos(), s);
        }
        miArchivo.close();
    } catch (SongsListException ex) {
        miArchivo.close();
        string error = "Hubo problemas al insertar leyendo desde el disco.\nEl error reportado es.";
        error += ex.what();
        throw SongsListException(error);
    }
}
