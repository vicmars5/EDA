#include "menu.h"
#include <iostream>
#include <cstdlib>
#include "song.h"
#include "list.h"

#ifdef WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define SONGS_FILE "songs.vic"

using namespace std;

void Menu::showMenu() {
    int option;
    do {
        system(CLEAR);

        cout << "\tRanking: " << endl;
        songList.printData();

        cout << "\tRANKING MUSICAL" << endl
             << "Menu:" << endl
             << " 1.-Añadir cancion" << endl
             << " 2.-Eliminar cancion" << endl
             << " 3.-Mostrar ranking" << endl
             << " 4.-Guardar en disco" << endl
             << " 5.-Leer de disco" << endl
             << " 6.-Buscar cancion" << endl
             << " 0.-Salir" << endl
             << "Opcion: ";
        cin >> option;
        cin.ignore();

        switch(option) {
        case 1:
            addSong();
            break;
        case 2:
            deleteSong();
            break;
        case 3:
            showSongs();
            break;
        case 4:
            try {
                songList.writeToDisk(SONGS_FILE);
                cout << "Guardado" << endl;
                cin.get();
            } catch(ListException ex) {
                cout << "No se pudo guardar" << endl;
            }
            break;
        case 5:
            try {
                songList.readFromDisk(SONGS_FILE);
            } catch(ListException ex) {
                cout << "No se pudo leer el archivo" << endl;
            }
            break;
        case 6:
            searchNameSong();
            break;
        case 0:
            break;
        default:
            system(CLEAR);
            cout << "ERROR, opcion invalida" << endl;
            break;
        }
    } while(option!=0);
}

void Menu::addSong() {
    bool answerError;
    Song song;
    string input;
    int numberIn;

    system(CLEAR);

    songList.printData();
    cout << "\tAñadir cancion" << endl;

    do {
        cout << "Nombre: ";
        getline(cin, input);

        if(input != "") {
            answerError=false;
        } else {
            cout << "ERROR, ingresa el nombre de la canción" << endl;
            answerError=true;
        }
    } while(answerError);
    song.setName(input);

    do {
        cout << "Autor: ";
        getline(cin, input);

        if(input != "") {
            answerError=false;
        } else {
            cout << "ERROR, ingresa el nombre del autor" << endl;
            answerError=true;
        }
    } while(answerError);
    song.setAuthor(input);

    do {
        cout << "Interprete: ";
        getline(cin, input);

        if(input != "") {
            answerError=false;
        } else {
            cout << "ERROR, ingresa el nombre del interprete" << endl;
            answerError=true;
        }
    } while(answerError);
    song.setPlayer(input);

    do {
        cout << "Puesto en el ranking: " << endl;
        cin >> numberIn;
        cin.ignore();
        if(numberIn > 0 and numberIn <= 50) {
            answerError=false;
        } else {
            cout << "ERROR, el ranking no es valido (1-50)" << endl;
            answerError=true;
        }
    } while(answerError);
    song.setRanking(numberIn);

    do {
        cout << "Nombre de archivo: ";
        getline(cin, input);

        if(input != "") {
            answerError=false;
        } else {
            cout << "ERROR, ingresa el nombre del archivo" << endl;
            answerError=true;
        }
    } while(answerError);
    song.setFile(input);

    try {
        songList.insertData(songList.getLastPos(), song);
    } catch(ListException ex) {
        cout << "ERROR, no se pudo guardar" << endl;
    }

    system(CLEAR);
    cout << "La cancion se guardo exitosamente" << endl << endl;
}

void Menu::deleteSong() {
    string name;
    Song s;

    system(CLEAR);
    songList.printData();

    cout << "Nombre de la cancion a eliminar" << endl;
    getline(cin, name);
    s.setName(name);

    system(CLEAR);
    try {
        songList.deleteData(songList.findData(s));
        cout << "Cancion eliminada" << endl;
    } catch(ListException ex) {
        cout << "ERROR, no se pudo eliminar la cancion" << endl;
    }
    cout << endl << endl;
}

void Menu::showSongs() {
    system(CLEAR);
    songList.printData();
    cout << "Presione \"Enter\" para continuar..." << endl;
    cin.get();
}


void Menu::searchNameSong() {
    string name;
    Song s;

    system(CLEAR);
    cout << "\tBusqueda por nombre" << endl
         << "Nombre de la cancion: ";
    getline(cin, name);
    cout << endl;

    s.setName(name);

    try {
        s = songList.retrieve(songList.findData(s));
    } catch (ListException ex) {
        cout << "No se encontro" << endl;
        cin.get();
        return;
    }

    cout << "Canción encontrada" << endl;
    cout << s;

    cin.get();
}

void Menu::showSong(Song s) {

    cout << "Nombre: " << s.getName() << endl;

}




