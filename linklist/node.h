#ifndef NODE_H
#define NODE_H
#include "student.h"
#include <cstring>
#include <iostream>

using namespace std;

class Node {
 public:
  Node(Student* student);
  ~Node();
  Student* getStudent();
  void setStudent(Student* student);
  Node* getNext();
  void setNext(Node* next);
 private:
  Student* student;
  Node* next;
};

#endif
