#include <string>
#include "TNode.hpp"
using namespace std;

TNode::TNode(string s): val(s), left(NULL), right(NULL) {}
string TNode::getVal() {return val;}
TNode* TNode::getLeft() {return left;}
TNode* TNode::getRight() {return right;}
void TNode::setLeft(TNode* t) {left = t;}
void TNode::setRight(TNode* t) {right = t;}

