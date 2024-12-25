#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

//Constructors
Media::Media(){
  this->year = 2024;
  this->title = new char[80];
}

Media::Media(int year, char* title){
  this->year = year;
  this->title = new char[80];
  strcpy(this->title, title);
}

//Destructor
Media::~Media(){
  delete this->title;
}

//Getters
int Media::getYear(){return this->year;}
char* Media::getTitle(){return this->title;}

//Methods
void Media::print(){
  cout << "---< Media >---" << endl;
  cout << "Title: " << this->title << endl;
  cout << "Year: " << this->year << endl;
  cout << "---------------" << endl;
}
