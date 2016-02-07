#include "menu.h"
#include <iostream>

#include "song.h"

using namespace std;

void Menu::showMenu(){
    int option;
    songsList.initialize();
    do{
        cout << "\tRANKING MUSICAL" << endl
                << "Menu:" << endl
                << "1.-Añadir cancion" << endl
                << "2.-Eliminar cancion" << endl
                << "3.-Mostrar ranking" << endl
                << "0.-Salir" << endl;
        cin >> option;
        cin.ignore();

        switch(option){
            case 1:
                addSong();
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                break;
            default:
                cout << "ERROR, invalid option";
                break;
        }
    }while(option!=0);
}

void Menu::addSong(){
    bool answerError;
    Song song;
    cout << "\tAñadir cancion" << endl;

    do{
        cout << "Nombre: ";
        getline(cin, song.name);

        if(song.name != ""){
            answerError=false;
        }
        else{
            cout << "ERROR, ingresa el nombre de la canción" << endl;
            answerError=true;
        }
    }while(answerError);

    do{
        cout << "Autor: ";
        getline(cin, song.author);

        if(song.author != ""){
            answerError=false;
        }
        else{
            cout << "ERROR, ingresa el nombre del autor" << endl;
            answerError=true;
        }
    }while(answerError);

    do{
        cout << "Interprete: ";
        getline(cin, song.player);

        if(song.player != ""){
            answerError=false;
        }
        else{
            cout << "ERROR, ingresa el nombre del interprete" << endl;
            answerError=true;
        }
    }while(answerError);

    do{
        cout << "Puesto en el ranking: " << endl;
        cin >> song.ranking;
        if(song.ranking > 0 and song.ranking <= 50){
            answerError=false;
        }
        else{
            cout << "ERROR, el ranking no es valido (1-50)" << endl;
            answerError=true;
        }
    }while(answerError);
    try{
        songsList.insertData(songsList.getLastPos(), song);
    }
    catch(SongsListException ex){
        cout << "ERROR, no se pudo guardar" << endl;
    }
}
