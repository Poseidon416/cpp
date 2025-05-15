#include <string>
#include "Stack.hpp"
using namespace std;

Stack::Stack() : LinkedList() {}

void Stack::push(string s) {
  Node* newNode = new Node(s);
  newNode->setNext(head);
  head = newNode;
}

string Stack::pop() {
  if(head == NULL){
    return "EMPTY";
  }
  Node* temp = head;
  string s = temp->getVal();
  head = head->getNext();
  delete temp;
  return s;
}

string Stack::peek() {
  return head->getVal();
}
