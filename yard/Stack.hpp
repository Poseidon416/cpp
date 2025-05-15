#include <string>
#include "LinkedList.h"
using namespace std;

class Stack: public LinkedList {
public:
  Stack();
  void push(string s);
  string pop();
  string peek();
};
