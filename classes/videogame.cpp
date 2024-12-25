#include <iostream>
#include <cstring>
#include "VideoGame.h"

using namespace std;

//Constructor
VideoGame::VideoGame(int year, char* title, char* publisher, float rating):
  Media(year, title){
  this->publisher = new char[80];
  strcpy(this->publisher, publisher);
  this->rating = rating;
}

//Destructor
VideoGame::~VideoGame(){
  delete this->publisher;
}

//Getters
char* VideoGame::getPublisher(){return this->publisher;}
float VideoGame::getRating(){return this->rating;}

void VideoGame::print(){
  cout << "---< Video Game >---" << endl;
  cout << "Title: " << this->title << endl;
  cout << "Year: " << this->year << endl;
  cout << "Publisher: " << this->publisher << endl;
  cout << "Rating: " << this->rating << "/10" << endl;
  cout << "--------------------" << endl;
}
