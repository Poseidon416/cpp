#include <iostream>
using namespace std;

struct node {
  int data;
  node * left;
  node * right;
  char color;
  node(int i, bool isRoot);
};

class RBT {
private:
  node * root;
public:
  RBT();
  void add(int i);
  void rotateLeft();
  void rotateRight();
  void display();
  node* search(int i);
  void erradicate(int i);
};
