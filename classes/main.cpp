#include <iostream>
#include <cstring>
#include <vector>

#include "Media.h"
#include "Movie.h"
#include "Music.h"
#include "VideoGame.h"

using namespace std;


//Function declarations:
void add(vector<Media*> &list, char fname[25], char lname[25], int id, float gpa);
void search(vector<Media*> &list);
void remove(vector<Media*> &list, int id);

int main(){
  vector<Media*> list;

  cout << "\033[H\033[2J"; //clear console

  cout << "\033[4m\033[1m" << "\t\tWELCOME TO MEDIA DATABASE" << "\033[0m" << endl;
  cout << "\033[1m" << "--------------------------------------------------------" << endl;
  cout << "  Available commands: \"ADD\", \"SEARCH\", \"DELETE\", \"QUIT\"" << endl;
  cout << "--------------------------------------------------------" << "\033[0m" << endl;

  bool running = true;
  while (running){
    char command[10];
    cout << "Enter command: ";
    cin >> command;
    
    if (strcmp(command, "ADD") == 0) {
      cout << "\033[1m-------- ADD --------\033[0m" << endl;
      cout << "What kind of media would you like to add?" << endl;
      cout << "\t1: Movie, 2: Music, 3: Video Game" << endl;
      int option;
      cout << "Enter number: ";
      cin >> option;
      
      cout << "\033[1m-------- END --------\033[0m" << endl;
    } else if (strcmp(command, "SEARCH") == 0) {
      
    } else if (strcmp(command, "DELETE") == 0) {
      cout << "\033[1m-------- DELETE --------\033[0m" << endl;
      
      cout << "\033[1m------------------------\033[0m" << endl;
    } else if (strcmp(command, "QUIT") == 0) {
      running = false;
    } else {
      cout << "That command doesn't exist." << endl;
    }
  }
  
  return 0;
}


