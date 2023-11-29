#include "iostream"
#include <string>

using namespace std;

class PlaylistNode {
  private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;

  public:
    PlaylistNode();
    // TODO: parameterized constructor

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
