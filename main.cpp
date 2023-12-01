// https://github.com/amsun1/zyLab-28.15
// Amanda Sun
// Bonita Davis

#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
   cout << endl << "Choose an option:" << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   if (option == 'o') {
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      if (headNode == NULL)
         cout << "Playlist is empty" << endl;
      else { // TODO: check if this part works after implementing "add song"
         PlaylistNode* currNode = headNode->GetNext();
         while (currNode != NULL) {
            currNode->PrintPlaylistNode();
            currNode = currNode->GetNext();
         }
      }
   }
   
   return headNode;
}

int main() {
   string playlistTitle;

   cout << "Enter playlist's title:" << endl << endl;
   getline(cin, playlistTitle);

   PlaylistNode* headNode = nullptr;

   char option;
   do {
      PrintMenu(playlistTitle);
      cin >> option;
      cin.ignore();

      headNode = ExecuteMenu(option, playlistTitle, headNode);
   } while(option != 'q');
   
   return 0;
}
