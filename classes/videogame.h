#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class VideoGame : public Media{
public:
  VideoGame(int year, char* title, char* publisher, float rating);
  virtual ~VideoGame();
  char* getPublisher();
  float getRating();
  void print();
private:
  char* publisher;
  float rating;
};
