#include "iostream"
#include <string>

#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

using namespace std;

class PlaylistNode {
  private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;

  public:
    PlaylistNode() {
      uniqueID = "none";
      songName = "none";
      artistName = "none";
      songLength = 0;
      nextNodePtr = 0;
    }

    PlaylistNode(string userId, string userSong, string userArtist, int userSongLength);

    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext(); // TODO: check if return type is correct
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);
    void PrintPlaylistNode();

};

#endif
