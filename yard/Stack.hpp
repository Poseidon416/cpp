#include <string>
#include "LinkedList.hpp"
using namespace std;

template <typename T>
class Stack: public LinkedList<T> {
public:
  Stack();
  void push(T v);
  T pop();
  T peek();
  bool isEmpty();
};

#include "Stack.tpp"
