#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << endl << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   if (option == 'a') {
      string userID, userSong, userArtist;
      int userSongLength;
      
      if (headNode == nullptr)
         headNode = new PlaylistNode();
      
      PlaylistNode* currNode = nullptr;
      PlaylistNode* lastNode = headNode;
      
      while (lastNode->GetNext() != nullptr) {
         lastNode = lastNode->GetNext();
      }

      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      getline(cin, userID);
      
      cout << "Enter song's name:" << endl;
      getline(cin, userSong);
      
      cout << "Enter artist's name:" << endl;
      getline(cin, userArtist);
      
      cout << "Enter song's length (in seconds):" << endl;
      cin >> userSongLength;

      currNode = new PlaylistNode(userID, userSong, userArtist, userSongLength);
      lastNode->InsertAfter(currNode);
   }

   if (option == 'd') {
      cout << "REMOVE SONG" << endl;
      string removeID;
      cout << "Enter song's unique ID:" << endl;
      cin >> removeID;
   
      PlaylistNode* prevNode = nullptr;
      PlaylistNode* currNode = headNode;
   
      while (currNode != nullptr && currNode->GetID() != removeID) {
         prevNode = currNode;
         currNode = currNode->GetNext();
      }
   
      if (currNode == nullptr)
         cout << "\"" << removeID << "\" not found." << endl;
      else {
         if (prevNode != nullptr)
            prevNode->SetNext(currNode->GetNext());
         else
            headNode = currNode->GetNext();
   
         cout << "\"" << currNode->GetSongName() << "\" removed." << endl;
         delete currNode;
      }
   }


   if (option == 'c') {
      int currentPos, newPos;
      cout << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:" << endl;
      cin >> currentPos;
      cout << "Enter new position for song:" << endl;
      cin >> newPos;

      if (currentPos < 1 || newPos < 1) {
         cout << "Invalid positions. Positions must be greater than or equal to 1." << endl;
      } else {
         PlaylistNode* prevNode = nullptr;
         PlaylistNode* currNode = headNode;
         int currentPosition = 1;

         while (currNode != nullptr && currentPosition != currentPos) {
            prevNode = currNode;
            currNode = currNode->GetNext();
            currentPosition++;
         }

         if (currNode == nullptr) {
            cout << "Invalid current position. Song not found." << endl;
         } else {
            if (prevNode != nullptr) {
               prevNode->SetNext(currNode->GetNext());
            } else {
               headNode = currNode->GetNext();
            }

            currentPosition = 1;
            PlaylistNode* insertPrev = nullptr;
            PlaylistNode* insertNext = headNode;

            while (insertNext != nullptr && currentPosition != newPos) {
               insertPrev = insertNext;
               insertNext = insertNext->GetNext();
               currentPosition++;
            }

            if (insertPrev != nullptr) {
               insertPrev->InsertAfter(currNode);
            } else {
               currNode->SetNext(headNode);
               headNode = currNode;
            }

            cout << "\"" << currNode->GetSongName() << "\" moved to position " << newPos << endl;
         }
      }
   }

   if (option == 's') {
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      string artistName;
      cout << "Enter artist's name:" << endl;
      cin.ignore();
      getline(cin, artistName);

      int position = 1;
      PlaylistNode* currNode = headNode;
      while (currNode != nullptr) {
         if (currNode->GetArtistName() == artistName) {
            cout << position << "." << endl;
            currNode->PrintPlaylistNode();
            cout << endl;
            position++;
         }
         currNode = currNode->GetNext();
      }
   }

   if (option == 't') {
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      int totalTime = 0;
      PlaylistNode* currNode = headNode;

      while (currNode != nullptr) {
         totalTime += currNode->GetSongLength();
         currNode = currNode->GetNext();
      }

      cout << "Total time: " << totalTime << " seconds" << endl;
   }

   if (option == 'o') {
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      if (headNode == nullptr) {
         cout << "Playlist is empty" << endl;
      } else {
         int position = 1;
         PlaylistNode* currNode = headNode;
         currNode = currNode->GetNext();
         while (currNode != nullptr) {
            cout << position << "." << endl;
            currNode->PrintPlaylistNode();
            currNode = currNode->GetNext();
            position++;
            if (currNode != nullptr)
               cout << endl;
         }
      }
   }

   return headNode;
}

int main() {
   string playlistTitle;

   cout << "Enter playlist's title:" << endl;
   getline(cin, playlistTitle);

   PlaylistNode* headNode = NULL;

   char option;
   do {
      PrintMenu(playlistTitle);
      cout << endl << "Choose an option:" << endl;
      cin >> option;
      cin.ignore();

      headNode = ExecuteMenu(option, playlistTitle, headNode);
   } while (option != 'q');

   return 0;
}
