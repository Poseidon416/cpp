#include <string>
using namespace std;

class TNode {
private:
  string val;
  TNode* left;
  TNode* right;
public:
  TNode(string s);
  string getVal();
  TNode* getLeft();
  TNode* getRight();
  void setLeft(TNode* t);
  void setRight(TNode* t);
};
