#ifndef SONGSLIST_H
#define SONGSLIST_H

#include <exception>

#include "song.h"

#define ARRAY_SIZE 1024

class SongsListException : public std::exception {
private:
    std::string msg;
public:
    explicit SongsListException(const char* message) : msg(message) {}
    explicit SongsListException(const std::string& message) :msg(message) {}
    virtual ~SongsListException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

class SongsList {
private:
    Song* data[ARRAY_SIZE];
    int last;
    bool isSort;
    bool isValidPos(int);
    void intercambia(Song*, Song*);

    //Sort data methods. "s" is the sort way, artist or name
    void sortDataBubble(char s);
    void sortDataShell(char s);
    void sortDataInsert(char s);
    void sortDataSelect(char s);

public:
    SongsList();
    void initialize();

    bool isEmpty();
    bool isFull();

    void insertData(int, const Song&);
    void deleteData(int);

    int getFirstPos();
    int getLastPos();
    int getPrevPos(int);
    int getNextPos(int);

    int findData(const string&);
    int findDataBinary(const string&);
    int findDataLineal(const string&);
    int findArtist(const string&);

    Song retrieve(int);

    void sortData(const char& s, const char& op);

    void printData();
    void showSong(const int& i);

    void deleteAll();

    void writeToDisk(const string);

    void readFromDisk(string);
};

#endif // SONGSLIST_H
