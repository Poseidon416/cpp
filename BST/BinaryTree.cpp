#include "BinaryTree.hpp"
#include <iostream>
using namespace std;

Node::Node(int i): val(i), left(NULL), right(NULL) {}
int Node::getVal() { return val;}
void Node::setVal(int i) { val = i;}
Node* Node::getLeft() { return left;}
Node* Node::getRight() { return right;}
void Node::setLeft(Node* n) { left = n;}
void Node::setRight(Node* n) { right = n;}

BinaryTree::BinaryTree(): root(NULL) {}
Node* BinaryTree::getRoot() { return root;}

void rAdd(Node* curr, int i) {
  if(i > curr->getVal()) {
    if (curr->getRight() == NULL) {
      curr->setRight(new Node(i));
    } else {
      rAdd(curr->getRight(), i);
    }
  } else if (i < curr->getVal()) {
    if (curr->getLeft() == NULL) {
      curr->setLeft(new Node(i));
    } else {
      rAdd(curr->getLeft(), i);
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
    rAdd(root, i);
  }
}

void rPrint(Node* curr, int depth = 0) {
  if (curr == NULL) return;

  rPrint(curr->getRight(), depth + 1);

  for(int i = 0; i < depth; i++) {
    cout << '\t';
  }
  cout << curr->getVal() << endl;

  rPrint(curr->getLeft(), depth + 1);
}
void printInorder(Node* curr) {
  if (curr == NULL) return;
  printInorder(curr->getLeft());
  cout << curr->getVal() << " ";
  printInorder(curr->getRight());
}
void BinaryTree::printTree() {
  rPrint(root);
  cout << "Inorder: ";
  printInorder(root);
  cout << endl;
}

Node* rSearch(Node* curr, int i) {
  if (curr == NULL || i == curr->getVal()) return curr;
  if (i > curr->getVal()) {
    return rSearch(curr->getRight(), i);
  }
  if (i < curr->getVal()) {
    return rSearch(curr->getLeft(), i);
  }
}
Node* BinaryTree::search(int i) {
  return rSearch(root, i);
}

void rDelete(Node* prev, Node* curr, int i) {
  if (curr == NULL) return;
  if (i < curr->getVal()) {
    rDelete(curr, curr->getLeft(), i);
  } else if (i > curr->getVal()) {
    rDelete(curr, curr->getRight(), i);
  } else {
    if(curr->getLeft() == NULL && curr->getRight() == NULL) {
      if(prev->getLeft() == curr) {
	prev->setLeft(NULL);
      } else {
	prev->setRight(NULL);
      }
      delete curr;
    } else if (curr->getRight() == NULL) {
      if(prev->getLeft() == curr) {
        prev->setLeft(curr->getLeft());
      } else {
        prev->setRight(curr->getLeft());
      }
      delete curr;
    } else if (curr->getLeft() == NULL) {
      if(prev->getLeft() == curr) {
        prev->setLeft(curr->getRight());
      } else {
        prev->setRight(curr->getRight());
      }
      delete curr;
    } else {
      Node* parent = curr;
      Node* predecessor = curr->getLeft();
      while (predecessor->getRight() != NULL) {
	cout << parent << endl;
	cout << predecessor << endl;
	parent = predecessor;
	predecessor = predecessor->getRight();
      }
      curr->setVal(predecessor->getVal());
      if (parent == curr) {
	parent->setLeft(predecessor->getLeft());
      } else {
	parent->setRight(predecessor->getLeft());
      }
      delete predecessor;
    }
  }
}
void BinaryTree::erradicate(int i) {
  rDelete(root, root, i);
}
