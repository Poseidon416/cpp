#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main() {
  BinaryTree * b = new BinaryTree();
  b->add(2);
  b->add(1);
  b->add(3);
  b->printTree();
  return 0;
}
