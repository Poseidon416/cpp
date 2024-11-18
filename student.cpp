#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

int main() {
  struct Student {
    char fname[25];
    char lname[25];
    int id;
    float gpa;
  };

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
      int id;
      cout << "Enter student ID: ";
      cin >> id;
      float gpa;
      cout << "Enter GPA: ";
      cin >> gpa;

      Student student;
      student.fname = fname;
      student.lname = lname;
      student.id = id;
      student.gpa = gpa;
      &student;
      list.push_back(&student);

      cout << "\033[1m-------- END --------\033[0m" << endl;
    } else if (strcmp(command, "PRINT") == 0) {

    } else if (strcmp(command, "DELETE") == 0) {

    } else if (strcmp(command, "QUIT") == 0) {
      running = false;
    } else {
      cout << "That command doesn't exist." << endl;
    }
  }
  return 0;
}
