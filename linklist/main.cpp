#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

int main(){
  char* fname = new char[25];
  char* lname = new char[25];
  strcpy(fname, "nikhil");
  strcpy(lname, "mantha");
  Student* s = new Student(fname, lname, 1, 2.7);  
  Student* s2 = new Student(fname, lname, 2, 4.3);
  Node* one = new Node(s);
  Node* two = new Node(s2);

  one->setNext(two);

  //Should display 1 then 2
  cout << one->getStudent()->getID() << endl;
  cout << one->getNext()->getStudent()->getID() << endl; //gets node two through node one

  delete fname;
  delete lname;
  delete s;
  delete s2;
  delete one;
  delete two;
  return 0;
}
