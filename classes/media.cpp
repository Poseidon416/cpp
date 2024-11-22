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

//Getters
int Media::getYear(){ return this->year; }

char* Media::getTitle(){ return this->title; }

//Setters
void Media::setYear(int year){
  this->year = year;
}

void Media::setTitle(char* title){
  strcpy(this->title, title);
}
