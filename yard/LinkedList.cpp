#include <string>
#include "LinkedList.hpp"

using namespace std;

Node::Node(string s): val(s), next(NULL) {}
Node* Node::getNext() { return next; }
void Node::setNext(Node* n) { next = n; }
string Node::getVal() { return val; }

LinkedList::LinkedList(){
  head = NULL; 
}

LinkedList::~LinkedList(){
  Node* current = head;
  while(current != NULL){
    Node* temp = current;
    current = current->getNext();
    delete temp;
  }
}

Node* LinkedList::getHead() { return head; }

