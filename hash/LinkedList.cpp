#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

Student::Student(string s, int i, float f): name(s), id(i), gpa(f) {}

string Student::getName(){ return name; }
int Student::getID() { return id; }
float Student::getGPA(){ return gpa; }

Student* Student::makeStudent() {
  string s;
  int i;
  float f;
  cout << "Enter name: ";
  getline(cin, name);
  cout << "Enter ID: ";
  cin >> id;
  cout << "Enter GPA: ";
  cin >> gpa;
  Student* st = new Student(s, i, f);
  return st;
}

Node::Node(Student* s): student(s), next(NULL) {}
Node::~Node(){
  delete student;
  next = NULL;
}

Node* Node::getNext(){ return next; }
void Node::setNext(Node* n) {
  next = n;
}

Student* Node::getStudent() { return student; }

LinkedList::LinkedList(Node* n): head(n) {}

void LinkedList::add(Node* n) {
  
}
