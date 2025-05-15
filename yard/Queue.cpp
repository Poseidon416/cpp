#include <string>
#include "Queue.hpp"
using namespace std;

Queue::Queue() : LinkedList() {
  tail = NULL;
}

void Queue::enqueue(string s) {
  Node* newNode = new Node(s);
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->setNext(newNode);
    tail = newNode;
  }
}

string Queue::dequeue() {
  if (head == NULL) {
    return "EMPTY";
  }
  Node* temp = head;
  string s = temp->getVal(); 
  if(head == tail) {
    tail = NULL;
  } 
  head = head->getNext();
  delete temp;
  return s;
}
