#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

//Constructor
Music::Music(int year, char* title, char* artist, char* publisher, int duration):
  Media(year, title){
  this->artist = new char[80];
  strcpy(this->artist, artist);
  this->publisher = new char[80];
  strcpy(this->publisher, publisher);
  this->duration = duration;
}

//Destructor
Music::~Music(){
  delete this->artist;
  delete this->publisher;
}

//Getters
char* Music::getArtist(){return this->artist;}
char* Music::getPublisher(){return this->publisher;}
int Music::getDuration(){return this->duration;}

//Methods
void Music::print(){
  cout << "---< Music >---" << endl;
  cout << "Title: " << this->title << endl;
  cout << "Year: " << this->year << endl;
  cout << "Artist: " << this->artist << endl;
  cout << "Publisher: " << this->publisher << endl;
  cout << "Duration: " << this->duration << " secs" << endl;
  cout << "---------------" << endl;
}

