#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class Media{
 public:
  Media();
  Media(int year, char* title);
  int getYear();
  char* getTitle();
  void setYear(int year);
  void setTitle(char* title);
 protected:
  int year;
  char* title;
};

#endif
