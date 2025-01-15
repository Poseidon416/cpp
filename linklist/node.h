#ifndef NODE_H
#define NODE_H
#include "student.h"
#include <cstring>
#include <iostream>

using namespace std;

class Node {
 public:
  Node(Student* student); //constructor, takes a student pointer as input
  ~Node(); //deletes node, student object, assosicated, and sets next to NULL
  Student* getStudent(); //returns corresponding student object pointer
  void setStudent(Student* student); //sets value of student pointer
  Node* getNext(); //returns pointer to next node
  void setNext(Node* next); //sets next node
 private:
  Student* student;
  Node* next;
};

#endif
