#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
 public:
  Student(char* fname, char* lname, int id, float gpa); //assigns values of all variables
  ~Student(); //deletes char* variables from heap to prevent leaks
  char* getFName(); 
  char* getLName();
  int getID();
  float getGPA();
 private:
  char* fname;
  char* lname;
  int id;
  float gpa;
};
#endif
