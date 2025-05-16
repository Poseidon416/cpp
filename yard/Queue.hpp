#include <string>
#include "LinkedList.hpp"
using namespace std;

class Queue: public LinkedList {
private:
  Node* tail;
public:
  Queue();
  void enqueue(string s);
  string dequeue();
};
