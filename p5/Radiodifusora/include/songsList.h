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
    Song data[ARRAY_SIZE];
    int last;
    bool isValidPos(int);
public:
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

    Song retrieve(int);

    void sortData();

    void printData();

    void deleteAll();

    void writeToDisk(string);

    void readFromDisk(string);
};

#endif // SONGSLIST_H
