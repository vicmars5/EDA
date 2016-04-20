#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {
private:
    int ranking;
    string name;
    string author;
    string player;
    string file;
public:
    Song();
    Song(const Song&);
    Song(int r, string n, string a, string p, string f);

    int getRanking();
    string getName();
    string getAuthor();
    string getPlayer();
    string getFile();

    void setRanking(const int&);
    void setName(const string&);
    void setAuthor(const string&);
    void setPlayer(const string&);
    void setFile(const string&);

    bool operator == (const Song &) const;

    friend ostream& operator << (ostream&, const Song& );
    friend istream& operator >> (istream&, Song&);
};


#endif // SONG_H
