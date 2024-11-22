#include <iostream>
#include <cstring>

#include "Media.h"
#include "Movie.h"
#include "Music.h"
#include "VideoGame.h"

using namespace std;

int main(){
  char* title = new char[80];
  strcpy(title, "George Orwell");
  char* director = new char[80];
  strcpy(director, "Poopy Mc.Poop the Shart");
  Movie* m = new Movie(1984, title, director, 192, 9.5);
  cout << m->getYear() << endl;
  cout << m->getTitle() << endl;
  cout << m->getDirector() << endl;
  cout << m->getDuration() << endl;
  cout << m->getRating() << endl;

  strcpy(title, "Luther");
  char* artist = new char[80];
  strcpy(artist, "Kendrick Lamar feat. SZA");
  char* publisher = new char[80];
  strcpy(publisher, "GNX");
  Music* mu = new Music(2024, title, artist, publisher, 156);
  cout << mu->getYear() << endl;
  cout << mu->getTitle() << endl;
  cout << mu->getArtist() << endl;
  cout << mu->getPublisher() << endl;
  cout << mu->getDuration() << endl;
  
  strcpy(publisher, "ASOBI");
  strcpy(title, "Astrobot");
  VideoGame* v = new VideoGame(2024, title, publisher, 9.7);
  cout << v->getYear() << endl;
  cout << v->getTitle() << endl;
  cout << v->getPublisher() << endl;
  cout << v->getRating() << endl;
  
  delete m;
  delete director;
  delete artist;
  delete publisher;
  delete mu;
  delete v;
  return 0;
}
