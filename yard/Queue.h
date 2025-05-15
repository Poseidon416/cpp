#include <string>
#include "LinkedList.h"
using namespace std;

class Queue: public LinkedList {
 public:
  Queue();
  void push(string s);
  string pop();
}
