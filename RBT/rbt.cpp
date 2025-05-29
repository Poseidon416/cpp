#include <iostream>
#include "RBT.hpp"
using namespace std;

node::node(int i, bool isRoot) {
  data = i;
  left = right = NULL;
  color = isRoot? 'B':'R';
}

