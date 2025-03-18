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

Student::Student(Student* s){
  name = s->getName();
  id = s->getID();
  gpa = s->getGPA();
}

string Student::getName(){ return name; }
int Student::getID() { return id; }
float Student::getGPA(){ return gpa; }

void Student::makeStudents(int amount) {}

Node::Node(Student* s): student(s), next(NULL) {}
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

LinkedList::~LinkedList(){
  Node* current = head;
  while(current != NULL){
    Node* temp = current;
    current = current->getNext();
    delete temp;
  }
}

Node* LinkedList::getHead() { return head; }

void LinkedList::add(Node* newNode, bool &reHash) {
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

