#ifndef SONG_H
#define SONG_H


class Song
{
    private:
        int ranking;
        string name;
        string author;
        string player;
        string file;
    public:
        Song();
        Song(int r, string n, string a, string p, string f);
        Song(Song& s);

        getRanking();
        getName();
        getAuthor();
        getPlayer();
        getFile();

        setRanking(int&);
        setName(string&);
        setAuthor(string&);
        setPlayer(string&);
        setFile(string&);



};

#endif // SONG_H
