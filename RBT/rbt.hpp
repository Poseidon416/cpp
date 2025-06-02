#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node* parent;
  char color;
  Node(int i, Node* parent, bool isRoot = false);
};

class RBT {
private:
  Node* root;
public:
  RBT();
  void add(int i);
  void display();
  Node* search(int i);
  void erradicate(int i);
};
