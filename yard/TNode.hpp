#include <string>
using namespace std;

template <typename T>
class TNode {
private:
  T val;
  TNode<T>* left;
  TNode<T>* right;
public:
  TNode(T v);
  T getVal();
  TNode<T>* getLeft();
  TNode<T>* getRight();
  void setLeft(TNode<T>* t);
  void setRight(TNode<T>* t);
};

#include "TNode.tpp"
