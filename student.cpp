#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

/* Nikhil Mantha
 *C++ & Data Structures
 *Student List
*/

struct Student {
  char fname[25];
  char lname[25];
  int id;
  float gpa;
};

void add(vector<Student*> &list, char fname[25], char lname[25], int id, float gpa);
void print(vector<Student*> &list);
void remove(vector<Student*> &list, int id);

int main() {

  vector<Student*> list;

  cout << "\033[H\033[2J";

  cout << "\033[4m\033[1m" << "\t\tWELCOME TO STUDENT LIST" << "\033[0m" << endl;
  cout << "\033[1m" << "--------------------------------------------------------" << endl;
  cout << "  Available commands: \"ADD\", \"PRINT\", \"DELETE\", \"QUIT\"" << endl;
  cout << "--------------------------------------------------------" << "\033[0m" << endl;
  
  bool running = true;
  while (running){
    char command[10];
    cout << "Enter command: ";
    cin >> command;

    if (strcmp(command, "ADD") == 0) {
      cout << "\033[1m-------- ADD --------\033[0m" << endl;

      char fname[25];
      cout << "Enter first name: ";
      cin >> fname;
      char lname[25];
      cout << "Enter last name: ";
      cin >> lname;

      bool valid = false;
      int id;
      while(!valid) {	
	cout << "Enter student ID: ";
	cin >> id;
	if(list.size() > 0) {
	  for(Student* student: list) {
	    if(id == student->id){
	      cout << "A student with that ID already exists." << endl;
	    } else { valid = true; }
	  }
	} else { valid = true; }
      }
      float gpa;
      cout << "Enter GPA: ";
      cin >> gpa;
       
      add(list, fname, lname, id, gpa);
      cout << "\033[1m-------- END --------\033[0m" << endl;
    } else if (strcmp(command, "PRINT") == 0) {
      print(list);
    } else if (strcmp(command, "DELETE") == 0) {
      cout << "\033[1m-------- DELETE --------\033[0m" << endl;
      int delID;
      cout << "Enter ID to delete: ";
      cin >> delID;

      char input[2];
      cout << "Are you sure you want to delete " << delID << "? (Y/N): ";
      cin >> input;
      if(input[0] == 'y' || input[0] == 'Y') {
	remove(list, delID);
      } 
      cout << "\033[1m------------------------\033[0m" << endl;
    } else if (strcmp(command, "QUIT") == 0) {
      running = false;
    } else {
      cout << "That command doesn't exist." << endl;
    }
  }
  return 0;
}

void add(vector<Student*> &list, char fname[25], char lname[25], int id, float gpa) {
  Student* student = new Student();
  strcpy(student->fname, fname);
  strcpy(student->lname, lname);
  student->id = id;
  student->gpa = gpa;
  list.push_back(student);
}

void print(vector<Student*> &list) {
  cout << "\033[1m-------- STUDENTS --------\033[0m" << endl;
  for(Student* student: list) {
    cout << student->fname << " " << student->lname\
    << ", ID: " << student->id << ", GPA: " << student->gpa << endl;
  }
  cout << "\033[1m--------------------------\033[0m" << endl;
}

void remove(vector<Student*> &list, int id) {
  for(int i = 0; i < list.size(); i++) {
    if(list.at(i)->id == id) {
      list.erase(list.begin()+i);
    }
  }
}
