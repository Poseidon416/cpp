#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class VideoGame : public Media{
public:
  VideoGame(int year, char* title, char* publisher, float rating);
  ~VideoGame();
  char* getPublisher();
  float getRating();
private:
  char* publisher;
  float rating;
};
