#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

//Constructor
Node::Node(Student* student){
  //initializes node's student pointer value
  this->student = student;
  next = NULL;
  
}

Node::~Node(){
  //deletes the student object assosciated with the node
  delete this->student;
  next = NULL;
}

//Getters
Student* Node::getStudent(){ return student; }
Node* Node::getNext(){ return next; }

//Setters
void Node::setStudent(Student* student){
  this->student = student;
};

void Node::setNext(Node* next) {
  this->next = next;
}
