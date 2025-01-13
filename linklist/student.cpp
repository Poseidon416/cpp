#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

//Constructor
Student::Student(char* fname, char* lname, int id, float gpa) {
  //initialize values of student variables
  this->fname = new char[25]; 
  strcpy(this->fname, fname);
  this->lname = new char[25];
  strcpy(this->lname, lname);
  this->id = id;
  this->gpa = gpa;
}

//Destructor
Student::~Student(){
  delete this->fname; //deletes variables that used 'new'
  delete this->lname; //to prevent memory leaks in the heap
}

//Getters
char* Student::getFName(){ return fname; }
char* Student::getLName(){ return lname; }
int Student::getID(){ return id; }
float Student::getGPA(){ return gpa; }
