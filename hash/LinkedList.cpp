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

Student::Student(string name, int id, float gpa){
  this->name = name;
  this->id = id;
  this->gpa = gpa;
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

void LinkedList::remove(Node* current, Node* &head, int id) {
  //Case: Deleting head
  if(head->getStudent()->getID() == id) {
    Node* temp = head; //stores in temp variable as head will be modified
    head = head->getNext(); //Makes next node new head
    delete temp; //deletes original head
    cout << "\033[1mDeleted student with ID: " << id << ".\033[0m" << endl;
    return;
  }
  //Case: Delete between 2 nodes or last node
  Node* next = current->getNext();
  if(next->getStudent()->getID() == id) {
    current->setNext(next->getNext());
    delete next;
    cout << "\033[1mDeleted student with ID: " << id << ".\033[0m" << endl;
    return;
  }
  //Case: No node was deleted
  if(current == NULL) { //if no student matched the id
    cout << "\033[1mStudent with ID: " << id << "was not found." << "\033[0m" << endl;
  }
  //Recurse: go to next node
  remove(next, head, id);
}
