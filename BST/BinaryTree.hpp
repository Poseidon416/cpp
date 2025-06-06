class Node {
private:
  int val;
  Node* left;
  Node* right;
public:
  Node(int i);
  int getVal();
  void setVal(int i);
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
  Node* getRoot();
  void add(int i);
  void printTree();
  Node* search(int i);
  void erradicate(int i);
};
