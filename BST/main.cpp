#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main() {
  BinaryTree * b = new BinaryTree();
  b->add(11);
  b->add(5);
  b->add(20);
  b->add(15);
  b->add(4);
  b->add(3);
  b->add(6);
  b->add(3);
  b->add(10);
  b->add(14);
  b->add(13);
  b->add(12);
  b->printTree();
  return 0;
}
