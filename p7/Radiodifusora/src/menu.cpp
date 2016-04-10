#include "menu.h"
#include <iostream>
#include <cstdlib>
#include "song.h"

#ifdef WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

void Menu::showMenu() {
    int option;
    songsList.initialize();
    do {

        system(CLEAR);
        cout << "\tRanking: " << endl;
        songsList.printData();

        cout << "\tRANKING MUSICAL" << endl
             << "Menu:" << endl
             << " 1.-Añadir cancion" << endl
             << " 2.-Eliminar cancion" << endl
             << " 3.-Mostrar ranking" << endl
             << " 4.-Guardar en disco" << endl
             << " 5.-Leer de disco" << endl
             << " 6.-Buscar cancion por nombre " << endl
             << " 7.-Buscar cancion por artista" << endl
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
                songsList.writeToDisk("songs list.vic");
                cout << "Guardado" << endl;
                cin.get();
            } catch(SongsListException ex) {
                cout << "No se pudo guardar" << endl;
            }
            break;
        case 5:
            try {
                songsList.readFromDisk("songs list.vic");
            } catch(SongsListException ex) {
                cout << "No se pudo leer el archivo" << endl;
            }
            break;
        case 6:
            searchNameSong();
            break;
        case 7:
            searchArtistSong();
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

    system(CLEAR);

    songsList.printData();
    cout << "\tAñadir cancion" << endl;

    do {
        cout << "Nombre: ";
        getline(cin, song.name);

        if(song.name != "") {
            answerError=false;
        } else {
            cout << "ERROR, ingresa el nombre de la canción" << endl;
            answerError=true;
        }
    } while(answerError);

    do {
        cout << "Autor: ";
        getline(cin, song.author);

        if(song.author != "") {
            answerError=false;
        } else {
            cout << "ERROR, ingresa el nombre del autor" << endl;
            answerError=true;
        }
    } while(answerError);

    do {
        cout << "Interprete: ";
        getline(cin, song.player);

        if(song.player != "") {
            answerError=false;
        } else {
            cout << "ERROR, ingresa el nombre del interprete" << endl;
            answerError=true;
        }
    } while(answerError);

    do {
        cout << "Puesto en el ranking: " << endl;
        cin >> song.ranking;
        cin.ignore();
        if(song.ranking > 0 and song.ranking <= 50) {
            answerError=false;
        } else {
            cout << "ERROR, el ranking no es valido (1-50)" << endl;
            answerError=true;
        }
    } while(answerError);

    do {
        cout << "Nombre de archivo: ";
        getline(cin, song.file);

        if(song.player != "") {
            answerError=false;
        } else {
            cout << "ERROR, ingresa el nombre del archivo" << endl;
            answerError=true;
        }
    } while(answerError);

    try {
        songsList.insertData(songsList.getLastPos(), song);
    } catch(SongsListException ex) {
        cout << "ERROR, no se pudo guardar" << endl;
    }

    system(CLEAR);
    cout << "La cancion se guardo exitosamente" << endl << endl;
}

void Menu::deleteSong() {
    string name;

    system(CLEAR);
    songsList.printData();

    cout << "Nombre de la cancion a eliminar" << endl;
    getline(cin, name);

    system(CLEAR);
    try {
        songsList.deleteData(songsList.findData(name));
        cout << "Cancion eliminada" << endl;
    } catch(SongsListException ex) {
        cout << "ERROR, no se pudo eliminar la cancion" << endl;
    }
    cout << endl << endl;
}

void Menu::showSongs() {
    system(CLEAR);
    char s; //Sort option
    char w; //Sort way

    cout << "Ordenar canciones por Artista [A] o Nombre [N]: ";
    cin >> s;
    cin.ignore();

    if (s == 'A' or s == 'N') {
        cout << "Metodo de ordenamiento" << endl
             << " b.-Burbuja" << endl
             << " i.-Insert" << endl
             << " s.-Select" << endl
             << " S.-Shell" << endl
             << "Opción: ";
        cin >> w;
        cin.ignore();

        if (w == 'b' or w == 'i' or w == 's' or w == 'S') {
            songsList.sortData(s, w);
        }
    }
    system(CLEAR);
    cout << "CANCIONES" << endl;
    songsList.printData();

    cout << "Presione \"Enter\" para continuar" << endl;
    cin.get();
}

void Menu::ifFinded(int index) {

    if(index >= 0) {
        cout << "\tCancion encontrada" << endl;
        showSong(index);
    } else {
        cout << "\tNo se encontro" << endl;
    }
    cin.get();
}

void Menu::searchNameSong() {
    string name;

    system(CLEAR);
    cout << "\tBusqueda por nombre" << endl
         << "Nombre de la cancion: ";
    getline(cin, name);
    cout << endl;

    ifFinded(songsList.findData(name));
}

void Menu::searchArtistSong() {
    string name;

    system(CLEAR);
    cout << "\tBusqueda por artista" << endl
         << "Nombre del artista: ";
    getline(cin, name);
    cout << endl;

    ifFinded(songsList.findArtist(name));
}

void Menu::showSong(const int& index) {
    Song s;
    s = songsList.retrieve(index);

    cout << "Nombre: " << s.name << endl
         << "Autor: " << s.author << endl
         << "Interprete: " << s.player << endl
         << "Ranking: " << s.ranking << endl
         << "Archivo: " << s.file << endl << endl;

}



