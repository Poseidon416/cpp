#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Music : public Media{
public:
  Music(int year, char* title, char* artist, char* publisher, int duration);
  virtual ~Music();
  char* getArtist();
  char* getPublisher();
  int getDuration();
  void print();
private:
  char* artist;
  char* publisher;
  int duration;
};
