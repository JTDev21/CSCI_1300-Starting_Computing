#ifndef PLAYLIST_H
#define PLAYLIST_h
#include <iostream>
#include <vector>

using namespace std;

class Playlist
{
    private:
        string playlistName;
        string currentSong;
        vector <string> songTitle;
        vector <string> songBand;
        vector <int> songId;
    public:
        Playlist();
        Playlist(string name);

        bool addSong(string name, string band, int Id);
        int playSongById(int Id);
        int playSongByTitle(string title);
        int getBandCount(string band);
};

#endif