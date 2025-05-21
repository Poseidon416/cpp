class Node {
private:
  int val;
  Node* left;
  Node* right;
public:
  Node();
  int getVal();
  Node* getLeft();
  Node* getRight();
  void setLeft(Node* n);
  void setRight(Node* n);
};

class BinaryTree {
private:
  Node* root;
public:
  BinaryTree();
};
