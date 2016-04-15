#ifndef MENU_H
#define MENU_H

#include "list.h"
#include "song.h"

class Menu {
public:
    void showMenu();
private:
    List<Song> songList;
    void addSong();
    void deleteSong();
    void showSongs();
    void showSong(Song);

    void searchNameSong();
};

#endif // MENU_H
