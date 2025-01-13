#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
 public:
  Student(char* fname, char* lname, int id, float gpa);
  ~Student();
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
