#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

Student::Student(){
  cout << "Enter name: ";
  getline(cin, name);
  cout << "Enter ID: ";
  cin >> id;
  cout << "Enter GPA: ";
  cin >> gpa;
}

string Student::getName(){ return name; }
int Student::getID() { return id; }
float Student::getGPA(){ return gpa; }

void Student::makeStudents(int amount) {}

Node::Node(): student(new Student()), next(NULL) {}
Node::~Node(){
  delete student;
  next = NULL;
}

Node* Node::getNext(){ return next; }
void Node::setNext(Node* n) {
  next = n;
}

Student* Node::getStudent() { return student; }

LinkedList::LinkedList(){
  head = NULL;
}

void LinkedList::add(bool &reHash) {
  Node* newNode = new Node();

  if (head == NULL) { //if linked list is empty
    head = newNode;
    return;
  }
  
  Node* last = head;
  int count = 1;
  while(last->getNext() != NULL) {
    last = last->getNext();
    count++;
  }
  last->setNext(newNode);

  reHash = (count == 4)? true:false;
}
