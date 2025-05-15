#include <string>
#include "LinkedList.h"
using namespace std;

class Queue: public LinkedList {
private:
  Node* tail;
public:
  Queue();
  void push(string s);
  string pop();
};
