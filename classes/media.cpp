#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

media::media() {
  this->year = 2024;
  this->title = new char[80];
}

media::media(int year, char* title) {
  this->year = year;
  strcpy(this->title, title);
}
