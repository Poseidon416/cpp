#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

int main() {
  media* m = new media();
  cout << m->year << endl;
  cout << m->title << endl;
  return 0;
}
