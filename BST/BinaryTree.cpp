#include "BinaryTree.hpp"
#include <iostream>
using namespace std;

Node::Node(int i): val(i), left(NULL), right(NULL) {}
int Node::getVal() { return val;}
Node* Node::getLeft() { return left;}
Node* Node::getRight() { return right;}
void Node::setLeft(Node* n) { left = n;}
void Node::setRight(Node* n) { right = n;}

BinaryTree::BinaryTree(): root(NULL) {}
Node* BinaryTree::getRoot() { return root;}

void recursiveAdd(Node* curr, int i) {
  if(i > curr->getVal()) {
    if (curr->getRight() == NULL) {
      curr->setRight(new Node(i));
    } else {
      recursiveAdd(curr->getRight(), i);
    }
  } else if (i < curr->getVal()) {
    if (curr->getLeft() == NULL) {
      curr->setLeft(new Node(i));
    } else {
      recursiveAdd(curr->getLeft(), i);
    }
  } else if (i == curr->getVal()) {
    cout << "Node(" << i << ") already exists." << endl;
    return;
  }
}
void BinaryTree::add(int i) {
  if (root == NULL) {
    root = new Node(i);
  } else {
    recursiveAdd(root, i);
  }
}

void recursivePrint(Node* curr, int depth = 0) {
  if (curr == NULL) return;

  recursivePrint(curr->getRight(), depth + 1);

  for(int i = 0; i < depth; i++) {
    cout << '\t';
  }
  cout << curr->getVal() << endl;

  recursivePrint(curr->getLeft(), depth + 1);
}
void BinaryTree::printTree() { recursivePrint(root); }
