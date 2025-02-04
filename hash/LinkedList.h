#include <string>

using namespace std;

class Student{
 private:
  string name;
  int id;
  float gpa;
 public:
  Student();
  string getName();
  int getID();
  float getGPA();
  void makeStudents(int amount);
};

class Node{
 private:
  Student* student;
  Node* next;
 public:
  Node();
  ~Node();
  Node* getNext();
  void setNext(Node* n);
  Student* getStudent();
};

class LinkedList{
 private:
  Node* head;
 public:
  LinkedList();
  void add(bool &reHash);
};
