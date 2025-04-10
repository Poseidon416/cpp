#include <string>

using namespace std;

class Student{
 private:
  string name;
  int id;
  float gpa;
 public:
  Student();
  Student(string name, int id, float gpa);
  Student(Student* s);
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
  Node(Student* s);
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
  ~LinkedList();
  Node* getHead();
  void add(Node* newNode, bool &reHash);
  void remove(Node* current, int id);
};
