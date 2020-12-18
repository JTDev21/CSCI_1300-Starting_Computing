#include "Playlist.h"
#include <iostream>
using namespace std;

Playlist::Playlist()
{
        playlistName= "Workout";
}

Playlist::Playlist(string name)
{
	playlistName= name;
}

bool Playlist::addSong(string name, string band, int Id)
{
	if (songTitle.size() < 100)
	{
		songTitle.push_back(name);
		songId.push_back(Id);
		songBand.push_back(band);

		return true;
        }

        return false;
}

int Playlist::playSongById(int Id)
{  
	for (int i=0 ; i < songTitle.size() ; i++) 
	{

		if(songId[i] == Id)
                {
                  currentSong = songTitle[i];
                  return 1;
                }
	}
  return -1;
}

int Playlist::playSongByTitle(string title)
{
  for (int i=0 ; i < songTitle.size() ; i++) 
   {
		if(songTitle[i] == title)
                {
                  currentSong = songTitle[i];
                  return 1;
                }
     }
  return -1;

}

int Playlist::getBandCount(string band)
{   
   int count = 0; 
   for (int i=0 ; i < songBand.size() ; i++) 
   {

		if(songBand[i] == band){
		    
                   count++;
		}
  }
   return count; 

}