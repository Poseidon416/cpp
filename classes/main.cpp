#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#include "Media.h"
#include "Movie.h"
#include "Music.h"
#include "VideoGame.h"

using namespace std;


//Function declarations:
void add(vector<Media*> &list);
void search(vector<Media*> &list);
void remove(vector<Media*> &list);

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
      cout << "\033[1m-------< ADD >-------\033[0m" << endl;
      add(list);
      cout << "\033[1m-------< END >-------\033[0m" << endl;
    } else if (strcmp(command, "SEARCH") == 0) {
      cout << "\033[1m-------< SEARCH >-------\033[0m" << endl;
      search(list);
      cout << "\033[1m------------------------\033[0m" << endl;
    } else if (strcmp(command, "DELETE") == 0) {
      cout << "\033[1m-------< DELETE >-------\033[0m" << endl;
      remove(list);
      cout << "\033[1m------------------------\033[0m" << endl;
    } else if (strcmp(command, "QUIT") == 0) {
      running = false;
    } else {
      cout << "That command doesn't exist." << endl;
    }
  }
  
  return 0;
}

void add(vector<Media*> &list) {
  cout << "What kind of media would you like to add?" << endl;
  cout << "   1: Movie, 2: Music, 3: Video Game" << endl;
  int option;
  cout << "Enter number: ";
  cin >> option;
  switch(option){
  case 1:{ //movie
    cout << "--< Adding Movie >--" << endl;
    int year;
    char* title = new char[80];
    char* director = new char[80];
    int duration;
    float rating;
    cout << "Enter year: ";
    cin >> year;
    cin.ignore();
    cout << "Enter title: ";
    cin.getline(title, 80);
    cout << "Enter director: ";
    cin.getline(director, 80);
    cout << "Enter duration: ";
    cin >> duration;
    cout << "Enter rating: ";
    cin >> rating;

    Movie* m = new Movie(year, title, director, duration, rating);
    list.push_back(m);

    delete title;
    delete director;
    break;
  }
  case 2:{ //music
    cout << "--< Adding Music >--" << endl;
    int year;
    char* title = new char[80];
    char* artist = new char[80];
    char* publisher = new char[80];
    int duration;
    cout << "Enter year: ";
    cin >> year;
    cin.ignore();
    cout << "Enter title: ";
    cin.getline(title, 80);
    cout << "Enter artist: ";
    cin.getline(artist, 80);
    cout << "Enter publisher: ";
    cin.getline(publisher, 80);
    cout << "Enter duration: ";
    cin >> duration;

    Music* mu = new Music(year, title, artist, publisher, duration);
    list.push_back(mu);

    delete title;
    delete artist;
    delete publisher;
    break;
  }  
  case 3:{ //videogame
    cout << "--< Adding Video Game >--" << endl;
    int year;
    char* title = new char[80];
    char* publisher = new char[80];
    float rating;
    cout << "Enter year: ";
    cin >> year;
    cin.ignore();
    cout << "Enter title: ";
    cin.getline(title, 80);
    cout << "Enter publisher: ";
    cin.getline(publisher, 80);
    cout << "Enter rating: ";
    cin >> rating;

    VideoGame* v = new VideoGame(year, title, publisher, rating);
    list.push_back(v);

    delete title;
    delete publisher;
    break;
  }
  }
}

void search(vector<Media*> &list){
  cout << "Would you like to search by year or title?" << endl;
  cout << "   1: Year, 2: Title" << endl;
  int option;
  cout << "Enter number: ";
  cin >> option;

  if(option == 1){//search by year
    int year;
    cout << "Enter year: ";
    cin >> year;
    for(int i = 0; i < list.size(); i++){
      if(list.at(i)->getYear() == year){
	list.at(i)->print();
      }
    }
  } else {//search by title
    char title[40];
    cout << "Enter title: ";
    cin.getline(title, 40, '\n');
    for(int i = 0; i < list.size(); i++){
      if(strcmp(list.at(i)->getTitle(), title) == 0){
	list.at(i)->print();
      }
    }
  }
}

void remove(vector<Media*> &list){
 cout << "Would you like to delete by year or title?" << endl;
  cout << "   1: Year, 2: Title" << endl;
  int option;
  cout << "Enter number: ";
  cin >> option;

  if(option == 1){//delete by year
    int year;
    cout << "Enter year: ";
    cin >> year;
    list.erase(remove_if(list.begin(), list.end(), [&](Media* m){
      if(m->getYear() == year){
	delete m;
	return true;
      }
      return false;
    }), list.end());
  } else {//delete by title
    char title[40];
    cout << "Enter title: ";
    cin.getline(title, 40, '\n');
    list.erase(remove_if(list.begin(), list.end(), [&](Media* m){
      if(strcmp(m->getTitle(), title) == 0){
        delete m;
        return true;
      }
      return false;
    }), list.end());
  }
}
