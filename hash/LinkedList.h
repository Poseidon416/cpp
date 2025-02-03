#include <string>

using namespace std;

class Student{
 private:
  string name;
  int id;
  float gpa;
 public:
  Student(string s, int i, float f);
  string getName();
  int getID();
  float getGPA();
  Student* makeStudent();
};

class Node{
 private:
  Student* student;
  Node* next;
 public:
  Node(Student* s);
  ~Node();
  Node* getNext();
  void setNext(Node* n);
  Student* getStudent();
};

class LinkedList{
 private:
  Node* head;
 public:
  LinkedList(Node* n);
  void add(Node* n);
};
