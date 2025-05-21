class Node {
private:
  int val;
  Node* left;
  Node* right;
public:
  Node(int i);
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
  Node* getRoot();
  void add(int i);
  void add(Node* curr, int i);
  void printTree();
  void printTree(Node* curr, int depth = 0);
};
