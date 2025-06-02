#include <iostream>
#include "RBT.hpp"
using namespace std;

//ALL ALGORITHMS ADAPTED FROM https://www.programiz.com/dsa/red-black-tree 

Node::Node(int i, Node* parent, bool isRoot) {
  data = i;
  left = right = NULL;
  this->parent = parent;
  color = isRoot? 'B':'R';
}

RBT::RBT():root(NULL) {}

void rotateLeft(Node*& root, Node* curr) {
  Node* right = curr->right;
  curr->right = right->left;
  if (right->left) {
    right->left->parent = curr;
  }

  right->parent = curr->parent;
  if (!curr->parent) {
    root = right;
  } else if (curr == curr->parent->left) {
    curr->parent->left = right;
  } else {
    curr->parent->right = right;
  }
  right->left = curr;
  curr->parent = right;
}

void rotateRight(Node*& root, Node* curr) {
  Node* left = curr->left;
  curr->left = left->right;
  if (left->right) {
    left->right->parent = curr;
  }

  left->parent = curr->parent;
  if (!curr->parent) {
    root = left;
  } else if (curr == curr->parent->left) {
    curr->parent->left = left;
  } else {
    curr->parent->right = left;
  }
  left->right = curr;
  curr->parent = left;
}

//programiz is a life-saver
void addFix(Node* &root, Node* curr) {
  while (curr != root && curr->parent->color == 'R') {
    Node* parent = curr->parent;
    Node* grandparent = parent->parent;
    if (!grandparent) break; //no need to fix tree is no grandparent (tree too small)
    
    if (parent == grandparent->left) { //curr is on left branch
      Node* uncle = grandparent->right;
      
      if (uncle != NULL &&uncle->color == 'R') { //uncle is red
        parent->color = 'B';
        uncle->color = 'B';
        grandparent->color = 'R';
	//fix up
        curr = grandparent;
      } else { //triangle fix
        if (curr == parent->right) {
          curr = parent;
          rotateLeft(root, curr);
	  //update vars
          parent = curr->parent;
          if(parent != NULL) {
	    grandparent = parent->parent;
	  } else {
	    grandparent = NULL;
	  }
        }
	//line fix
        if (parent != NULL) parent->color = 'B';
        if (grandparent != NULL) grandparent->color = 'R';
        rotateRight(root, grandparent);
      }
      
    } else { //curr is on right branch
      Node* uncle = grandparent->left;
      
      if (uncle != NULL && uncle->color == 'R') {
        parent->color = 'B';
        uncle->color = 'B';
        grandparent->color = 'R';
	//fix up
        curr = grandparent;
      } else {//triangle fix (opposite)
        if (curr == parent->left) {
          curr = parent;
          rotateRight(root, curr);
          //update vars
          parent = curr->parent;
          if(parent != NULL) {
            grandparent = parent->parent;
          } else {
            grandparent = NULL;
          }
        }
	//line fix
        if (parent != NULL) parent->color = 'B';
        if (grandparent != NULL) grandparent->color = 'R';
        rotateLeft(root, grandparent);
      }
    }
  }
  //always makes sure root is black
  if (root) root->color = 'B';
}

Node* addHelper(Node* &root, Node* &curr, int i) {
  if(i > curr->data) {//traverse right
    if (!curr->right) {
      curr->right = new Node(i, curr);
      return curr->right;
    } else {
      return addHelper(root, curr->right, i);
    }
  } else if (i < curr->data) {//traverse left
    if (!curr->left) {
      curr->left = new Node(i, curr);
      return curr->left;
    } else {
      return addHelper(root, curr->left, i);
    }
  } else if (i == curr->data) {
    cout << "Node(" << i << ") already exists." << endl;
    return NULL;
  }
}

void RBT::add(int i) {
  if (!root) {
    root = new Node(i, NULL, true);
  } else {
    addFix(root, addHelper(root, root, i));
  }
}

void displayHelper(Node* curr, int depth = 0) {
  if (!curr) return;

  displayHelper(curr->right, depth + 1);
  
  for (int i = 0; i < depth; i++) {
    cout << '\t';
  }
  if (curr->parent != NULL) {
    cout << "(" << curr->parent->data << ") ";
  }
  if (curr->color == 'R') { //red
    cout << "\033[31m" << curr->data << "\033[0m" << endl;
  } else { //black
    cout << "\033[7m" << curr->data << "\033[0m" << endl;
  }
  
  displayHelper(curr->left, depth + 1);
}

void RBT::display() {
  displayHelper(root);
}

Node* searchHelper(Node* curr, int i) {
  if (!curr || i == curr->data) return curr;
  if (i > curr->data) {
    return searchHelper(curr->right, i);
  }
  if (i < curr->data) {
    return searchHelper(curr->left, i);
  }
}

Node* RBT::search(int i) {
  return searchHelper(root, i);
}

//replaces one node with another
void transplant(Node* &root, Node* curr, Node* replacement) {
  if (curr == root) {//replace root
    root = replacement;
  } else if (curr->parent->left == curr) { //replace
    curr->parent->left = replacement;
  } else {
    curr->parent->right = replacement;
  }
  if(replacement != NULL) { //update replacement's parent
    replacement->parent = curr->parent;
  }
}

//null is equivalent to black
void deleteFix(Node* &root, Node* curr) {
  while (curr != root && (!curr || curr->color == 'B')) {
    if (!curr) break;
    if (curr == curr->parent->left) {//left child
      Node* sibling = curr->parent->right;
      if (sibling != NULL && sibling->color == 'R') {//red sibling
	sibling->color = 'B';
	curr->parent->color = 'R';
	rotateLeft(root, curr->parent);
	sibling = curr->parent->right;
      }
      //both sibling's children are black
      if ((!sibling || sibling->left->color == 'B') && (!sibling || sibling->right->color == 'B')) {
	sibling->color = 'R';
	curr = curr->parent;
      } //sibling is black, sibling's right child is black left child is red
      else if (!sibling->right || sibling->right->color == 'B') {
	sibling->left->color = 'B';
	sibling->color = 'R';
	rotateRight(root, sibling);
	sibling = curr->parent->right;
      }
      //sibling is black, sibling's right child is red
      sibling->color = curr->parent->color;
      curr->parent->color = 'B';
      sibling->right->color = 'B';
      rotateLeft(root, curr->parent);
    } else { //mirrored above but swapping left and rights (right child)
      Node* sibling = curr->parent->left;
      if (sibling != NULL && sibling->color == 'R') {//red sibling
        sibling->color = 'B';
        curr->parent->color = 'R';
        rotateRight(root, curr->parent);
        sibling = curr->parent->left;
      }
      //both sibling's children are black
      if ((!sibling || sibling->right->color == 'B') && (!sibling || sibling->left->color == 'B')) {
        sibling->color = 'R';
        curr = curr->parent;
      } //sibling is black, sibling's left child is black right child is red
      else if (!sibling->left || sibling->left->color == 'B') {
        sibling->right->color = 'B';
        sibling->color = 'R';
        rotateLeft(root, sibling);
        sibling = curr->parent->left;
      }
      //sibling is black, sibling's left child is red
      sibling->color = curr->parent->color;
      curr->parent->color = 'B';
      sibling->left->color = 'B';
      rotateRight(root, curr->parent);
    }
  }
  if (root != NULL) root->color = 'B';
}

void deleteHelper(Node* &root, Node* curr, int i) {
  if (!curr) return; //Node not found
  if (i < curr->data) {
    deleteHelper(root, curr->left, i);
  } else if (i > curr->data) {
    deleteHelper(root, curr->right, i);
  } else { //node found
    char originalColor = curr->color;
    Node* x = NULL;
    if(!curr->left){ //right child
      x = curr->right;
      transplant(root, curr, x);
    } else if (!curr->right) { //left child
      x = curr->left;
      transplant(root, curr, x);
    } else { //2 child
      Node* successor = curr->right;
      while(successor->left != NULL) {
	successor = successor->left;
      }
      originalColor = successor->color;
      x = successor->right;
      if (successor->parent != curr) {
        transplant(root, successor, x);
        successor->right = curr->right;
        if (successor->right != NULL) {
	  successor->right->parent = successor;
	}
      }
      transplant(root, curr, successor);
      successor->left = curr->left;
      if (successor->left != NULL) {
	successor->left->parent = successor;
      }
      successor->color = curr->color;
    }
    delete curr;
    if (originalColor == 'B') {
      deleteFix(root, x); 
    }
  }
}

void RBT::erradicate(int i) {
  deleteHelper(root, root, i);
}
