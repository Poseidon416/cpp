#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
using namespace std;

template <typename T>
class Node{
 private:
  T val;
  Node<T>* next;
 public:
  Node(T v);
  Node<T>* getNext();
  void setNext(Node<T>* n);
  T getVal();
};

template <typename T>
class LinkedList{
 protected:
  Node<T>* head;
 public:
  LinkedList();
  ~LinkedList();
  Node<T>* getHead();
};

#include "LinkedList.tpp"

#endif
