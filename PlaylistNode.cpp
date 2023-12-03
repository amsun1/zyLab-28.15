#include "PlaylistNode.h"
#include <iostream>

// Constructor
PlaylistNode::PlaylistNode(string userID, string userSong, string userArtist, int userSongLength) {
  uniqueID = userID;
  songName = userSong;
  artistName = userArtist;
  songLength = userSongLength;
  nextNodePtr = 0;
}

// Accessor functions
string PlaylistNode::GetID() {return uniqueID;}
string PlaylistNode::GetSongName() {return songName;}
string PlaylistNode::GetArtistName() {return artistName;}
int PlaylistNode::GetSongLength() {return songLength;}
PlaylistNode* PlaylistNode::GetNext() {return nextNodePtr;}

// TODO: Mutator functions
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
  PlaylistNode* temp = nextNodePtr;
  nextNodePtr = nodePtr;
  nodePtr->nextNodePtr = temp;
}
void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
  nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
  cout << "Unique ID: " << uniqueID << endl;
  cout << "Song Name: " << songName << endl;
  cout << "Artist Name: " << artistName << endl;
  cout << "Song Length (in seconds): " << songLength << endl;
}
