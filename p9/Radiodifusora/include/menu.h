#ifndef MENU_H
#define MENU_H

#include "songsList.h"

class Menu {
public:
    void showMenu();
private:
    SongsList songsList;
    void addSong();
    void deleteSong();
    void showSongs();
    void showSong(const int& index);

    void ifFinded(int index);
    void searchNameSong();
    void searchArtistSong();
};

#endif // MENU_H
