#include "PlaylistNode.h"

// Accessor functions
string PlaylistNode::GetID() {return uniqueID;}
string PlaylistNode::GetSongName() {return songName;}
string PlaylistNode::GetArtistName() {return artistName;}
int PlaylistNode::GetSongLength() {return songLength;}
// TODO: PlaylistNode* PlaylistNode::GetNext() {}

// TODO: Mutator functions
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {

}
void PlaylistNode::SetNext(PlaylistNode* nodePtr) {

}

void PrintPlaylistNode() {
  cout << "Unique ID: " << uniqueID << endl;
  cout << "Song Name: " << songName << endl;
  cout << "Artist Name: " << artistName << endl;
  cout << "Song Length (in seconds): " << songLength << endl;
}
