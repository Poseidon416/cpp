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

void rDelete(Node* &root, Node* prev, Node* curr, int i) {
  if (curr == NULL) return; //node not found
  if (i < curr->getVal()) { //traverse left
    rDelete(root, curr, curr->getLeft(), i);
  } else if (i > curr->getVal()) { //traverse right
    rDelete(root, curr, curr->getRight(), i);
  } else { //node found
    if (curr == root) { //root cases
      if(root->getLeft() == NULL && root->getRight() == NULL) { //no children
        Node* temp = root;
	root = NULL;
	delete temp;
      } else if (curr->getRight() == NULL) { //left child
        Node* temp = root;
	root = root->getLeft();
	delete temp;
      } else if (curr->getLeft() == NULL) { //right child
        Node* temp = root;
	root = root->getRight();
	delete temp;
      } else { //2 children
        Node* predecessor = root->getLeft();
        while (predecessor->getRight() != NULL) {
          predecessor = predecessor->getRight();
        }
        int predVal = predecessor->getVal();
        root->setVal(predVal);
        rDelete(root, root, root->getLeft(), predVal);
      }
    } else { //other nodes
      if(curr->getLeft() == NULL && curr->getRight() == NULL) { //no children
	if(prev->getLeft() == curr) {
	  prev->setLeft(NULL);
	} else {
	  prev->setRight(NULL);
	}
	delete curr;
      } else if (curr->getRight() == NULL) { //left child
	if(prev->getLeft() == curr) {
	  prev->setLeft(curr->getLeft());
	} else {
	  prev->setRight(curr->getLeft());
	}
	delete curr;
      } else if (curr->getLeft() == NULL) { //right child
	if(prev->getLeft() == curr) {
	  prev->setLeft(curr->getRight());
	} else {
	  prev->setRight(curr->getRight());
	}
	delete curr;
      } else { //2 children
	Node* predecessor = curr->getLeft();
	while (predecessor->getRight() != NULL) {
	  predecessor = predecessor->getRight();
	}
	int predVal = predecessor->getVal();
	curr->setVal(predVal);
	rDelete(root, curr, curr->getLeft(), predVal);
      }
    }
  }
}
void BinaryTree::erradicate(int i) {
  rDelete(root, root, root, i);
}
