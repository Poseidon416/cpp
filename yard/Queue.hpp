#include <string>
#include "LinkedList.hpp"
using namespace std;

template <typename T>
class Queue: public LinkedList<T> {
private:
  Node<T>* tail;
public:
  Queue();
  void enqueue(T v);
  T dequeue();
  bool isEmpty();
  void print();
};

#include "Queue.tpp"
