#include <string>
#include "Queue.h"
using namespace std;

Queue::Queue() : LinkedList() {}

void Queue::push(string s) {
  Node* newNode = new Node(s);
}
