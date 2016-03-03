#ifndef MENU_H
#define MENU_H

#include "songsList.h"

class Menu {
public:
    void showMenu();
protected:
    SongsList songsList;
    void addSong();
    void deleteSong();
    void showSongs();
private:
};

#endif // MENU_H
