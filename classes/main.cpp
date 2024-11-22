#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

int main(){
  char* title = new char[80];
  strcpy(title, "George Orwell");
  Media* m = new Media();
  m->setYear(1984);
  m->setTitle(title);
  cout << m->getYear() << endl;
  cout << m->getTitle() << endl;
  return 0;
}
