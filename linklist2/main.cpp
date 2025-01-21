#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

// Function declarations
void add(Node* current, Node* &head, Student* student);
void print(Node* node);
float average(Node* node, float total, int count);
float round(float num);
void remove(Node* current, Node* &head, int id);

int main(){
  cout << "\033[H\033[2J"; //clear console

  cout << "\033[4m\033[1m" << "\t\tWELCOME TO STUDENT LIST" << "\033[0m" << endl;
  cout << "\033[1m" << "-------------------------------------------------------" << endl;
  cout << " Commands: \"ADD\", \"PRINT\", \"AVERAGE\", \"DELETE\", \"QUIT\"" << endl;
  cout << "-------------------------------------------------------" << "\033[0m" << endl;

  Node* head = NULL; // initalize head of empty linked list
  
  bool running = true;
  while (running){
    // takes user input for command
    char command[10];
    cout << "Enter command: ";
    cin >> command;

    if (strcmp(command, "ADD") == 0) { //adds a student to the linked list
      cout << "\033[1m-------- ADD --------\033[0m" << endl;
      //take user input for all variables of Student
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
      gpa = round(gpa); //rounds to 2 decimal places

      Student* student = new Student(fname, lname, id, gpa);
      add(head, head, student);

      cout << "\033[1m-------- END --------\033[0m" << endl;
    } else if (strcmp(command, "PRINT") == 0) { // prints all students currently in list
      cout << "\033[1m-------- STUDENTS --------\033[0m" << endl;

      if (head == NULL) { // notifies user that linked list is empty
        cout << "\033[1mThere are no students to print.\033[0m" << endl;
      } else {
        print(head); 
      }
      
      cout << "\033[1m--------------------------\033[0m" << endl;
    } else if (strcmp(command, "AVERAGE") == 0) {

      if (head == NULL) { // notifies user that linked list is empty to avoid -nan
	cout << "\033[1mThere are no students to average.\033[0m" << endl;
      } else {
	cout << "\033[1m" << "Average GPA: " << average(head, 0, 0) << "\033[0m" << endl;
      }
      
    } else if (strcmp(command, "DELETE") == 0) { // deletes student based on their ID
      cout << "\033[1m-------- DELETE --------\033[0m" << endl;

      if (head == NULL) {
	cout << "\033[1mThere are no students to delete.\033[0m" << endl;
      } else { //if list isn't empty then prompts to delete a student.
	int delID;
	cout << "Enter ID to delete: ";
	cin >> delID;
	//double checks if user wants to delete that ID
	char input[2];
	cout << "Are you sure you want to delete " << delID << "? (Y/N): ";
	cin >> input;
	if(input[0] == 'y' || input[0] == 'Y') {
	  remove(head, head, delID);
	} else {
	  cout << "\033[1mCanceled\033[0m" << endl; // remove did not run
	}
      }

      cout << "\033[1m------------------------\033[0m" << endl;
    } else if (strcmp(command, "QUIT") == 0) {
      running = false; //ends while loop
    } else {
      cout << "That command doesn't exist." << endl;
    }
  }

  return 0;
}

void add(Node* current, Node* &head, Student* student){
  //Case: List is empty or new node must be placed before the head node.
  if (head == NULL || head->getStudent()->getID() > student->getID()){
    Node* newNode = new Node(student);
    newNode->setNext(head); //if list is empty then head is null
    head = newNode;
    return;
  }
  //Case: Node must be placed at end of list or between 2 nodes.
  Node* next = current->getNext();
  if (next == NULL || next->getStudent()->getID() > student->getID()) {
    Node* newNode = new Node(student);
    newNode->setNext(next);
    current->setNext(newNode);
    return;
  }
  //Recurse: go to next node
  add(next, head, student);
}

float round(float num){ //Rounds to 2 decimal places
  /*How it works:
   * assume num = 3.64513 (should round to 3.65)
   *  ->multiplies by 100 then adds .5
   * num = 364.5 + .5 = 365.13 (adding .5 "rounds" it)
   *  ->casting to int removes decimals
   * num = 365
   *  ->dividing by 100.0 converts to float
   * result: num = 3.65
   */
  return (int)(num*100 + 0.5)/100.0;
}

void print(Node* node) {
  //Base Case: exits when at the end of list
  if(node == NULL){
    return;
  }
  //Print current student:
  Student* s = node->getStudent();
  cout << "   - Name: " << s->getFName() << " " << s->getLName() << endl;
  cout << "     ID: " << s->getID() << endl;
  cout << "     GPA: " << s->getGPA() << endl;
  //Recurse: to next node
  print(node->getNext());
}

float average(Node* node, float total, int count) {
  //Base Case: end of list
  if(node == NULL) {
    //returns added up gpa divided by number of students to average it.
    return (total/count);
  }
  //Recurse: goes to next node, adds current students gpa to total, increments count
  return average(node->getNext(), (total+node->getStudent()->getGPA()), ++count);
}

void remove(Node* current, Node* &head, int id) {
  //Case: Deleting head
  if(head->getStudent()->getID() == id) {
    Node* temp = head; //stores in temp variable as head will be modified
    head = head->getNext(); //Makes next node new head
    delete temp; //deletes original head
    cout << "\033[1mDeleted student with ID: " << id << ".\033[0m" << endl;
    return;
  }
  //Case: Delete between 2 nodes or last node
  Node* next = current->getNext();
  if(next->getStudent()->getID() == id) {
    current->setNext(next->getNext());
    delete next;
    cout << "\033[1mDeleted student with ID: " << id << ".\033[0m" << endl;
    return;
  }
  //Case: No node was deleted
  if(current == NULL) { //if no student matched the id
    cout << "\033[1mStudent with ID: " << id << "was not found." << "\033[0m" << endl;
  }
  //Recurse: go to next node
  remove(next, head, id);
}
