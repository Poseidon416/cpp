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
  delete this->duration;
}

//Getters
char* Music::getArtist(){return this->artist;}
char* Music::getPublisher(){return this->publisher;}
int Music::getDuration(){return this->duration;}
