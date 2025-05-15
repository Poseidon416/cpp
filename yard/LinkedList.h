#include <string>
using namespace std;

class Node{
 private:
  string val;
  Node* next;
 public:
  Node(string s);
  Node* getNext();
  void setNext(Node* n);
  string getVal();
};

class LinkedList{
 protected:
  Node* head;
 public:
  LinkedList();
  ~LinkedList();
  Node* getHead();
};
