#include "song.h"

Song::Song() {

}

Song::Song(int r, string n, string a, string p, string f) {
    ranking = r;
    name = n;
    author = a;
    player = p;
    file = f;
}

Song::Song(const Song& s) : Song() {
    ranking = s.ranking;
    name = s.name;
    author = s.author;
    player = s.player;
    file = s.file;

}

int Song::getRanking() {
    return ranking;
}

string Song::getName() {
    return name;
}

string Song::getAuthor() {
    return author;
}

string Song::getPlayer() {
    return player;
}

string Song::getFile() {
    return file;
}
void Song::setRanking(const int& r) {
    ranking = r;
}

void Song::setName(const string& n) {
    name = n;
}

void Song::setAuthor(const string& a) {
    author = a;
}

void Song::setPlayer(const string& p) {
    player = p;
}

void Song::setFile(const string& f) {
    file = f;
}

bool Song::operator == (const Song &s) const {
    return (this->name == s.name);
}

ostream& operator << (ostream& o, const Song& s) {
    o << s.ranking << endl
      << s.name << endl
      << s.author << endl
      << s.player << endl
      << s.file << endl;
    return o;
}

istream& operator >> (istream& input, Song& s) {
    string myString;

    if(getline(input, myString))
        s.ranking = atoi(myString.c_str());

    if(getline(input, myString))
        s.name = myString;

    if(getline(input, myString))
        s.author = myString;

    if(getline(input, myString))
        s.player = myString;

    if(getline(input, myString))
        s.file = myString;

    return input;
}

