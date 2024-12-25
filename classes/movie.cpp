#include <iostream>
#include <cstring>
#include "Movie.h"

using namespace std;

//Constructor
Movie::Movie(int year, char* title, char* director, int duration, float rating):
  Media(year, title){
  this->director = new char[80];
  strcpy(this->director, director);
  this->duration = duration;
  this->rating = rating;
}

//Destructor
Movie::~Movie(){
  delete this->director;
}

//Getters
char* Movie::getDirector(){return this->director;}
int Movie::getDuration(){return this->duration;}
float Movie::getRating(){return this->rating;}

//Methods
void Movie::print(){
  cout << "---< Movie >---" << endl;
  cout << "Title: " << this->title << endl;
  cout << "Year: " << this->year << endl;
  cout << "Director: " << this->director << endl;
  cout << "Duration: " << this->duration << " mins" << endl;
  cout << "Rating: " << this->rating << "/10" << endl;
  cout << "---------------" << endl;
}
