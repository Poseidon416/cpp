#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

using namespace std;

int hashbrown(int id, int tableSize);
void nullify(LinkedList** &hashTable, int tableSize);
void rehash(LinkedList** &hashTable, int &tableSize);

int main(){
  cout << "\033[H\033[2J"; //clear console

  cout << "\033[4m\033[1m" << "\t\tWELCOME TO STUDENT LIST" << "\033[0m" << endl;
  cout << "\033[1m" << "-------------------------------------------------------" << endl;
  cout << " Commands: \"ADD\", \"FILE\", \"PRINT\", \"DELETE\", \"QUIT\"" << endl;
  cout << "-------------------------------------------------------" << "\033[0m" << endl;

  int tableSize = 101;
  LinkedList** hashTable = new LinkedList*[tableSize];
  nullify(hashTable, tableSize);
  
  bool running = true;
  while (running){
    // takes user input for command
    string command;
    cout << "Enter command: ";
    cin >> command;
    cin.ignore();
    
    if (command == "ADD") { //adds a student to the linked list
      cout << "\033[1m-------- ADD --------\033[0m" << endl;
      Node* n = new Node();
      int id = n->getStudent()->getID();
      int index = hashbrown(id, tableSize);
      if(hashTable[index] == NULL){
	hashTable[index] = new LinkedList();
      }
      bool reHash = false;
      hashTable[index]->add(n, reHash);
      if(reHash) {
	rehash(hashTable, tableSize);
      }
      cout << "\033[1m-------- END --------\033[0m" << endl;
    } else if (command == "FILE") {
      fstream file("students.txt");
      
      string name;
      string strID;
      string strGPA;
      while (getline(file, name, ',')){
	getline(file, strID, ',');
	getline(file, strGPA);
	int id = stoi(strID);
	float gpa = stof(strGPA);
	
	int index = hashbrown(id, tableSize);
	Node* newNode = new Node(new Student(name, id, gpa));
	bool reHash = false;

	if(hashTable[index] == NULL){
	  hashTable[index] = new LinkedList();
	}
	hashTable[index]->add(newNode, reHash);
	if(reHash) {
	  rehash(hashTable, tableSize);
	}
      }
      file.close();
    } else if (command == "PRINT") { // prints all students currently in list
      cout << "\033[1m-------- STUDENTS --------\033[0m" << endl;
      for(int i = 0; i < tableSize; i++){
	if(hashTable[i] != NULL){
	  Node* current = hashTable[i]->getHead();
	  while(current != NULL){
	    Student* s = current->getStudent();
	    cout << "   - Name: " << s->getName() << endl;
	    cout << "     ID: " << s->getID() << endl;
	    cout << "     GPA: " << s->getGPA() << endl;
	    current = current->getNext();
	  }
	}
      }
      cout << "\033[1m--------------------------\033[0m" << endl;
    } else if (command == "DELETE") { // deletes student based on their ID
      cout << "\033[1m-------- DELETE --------\033[0m" << endl;
      int delID;
      cout << "Enter ID: ";
      cin >> delID;
      int delindex = hashbrown(delID, tableSize);
      hashTable[delindex]->remove(hashTable[delindex]->getHead(), delID);
      cout << "\033[1m------------------------\033[0m" << endl;
    } else if (command == "QUIT") {
      running = false; //ends while loop
    } else {
      cout << "That command doesn't exist." << endl;
    }
  }
  return 0;
}

int hashbrown(int id, int tableSize){
  return (id % tableSize);
}

void nullify(LinkedList** &hashTable, int tableSize){
  for(int i = 0; i < tableSize; i++){
    hashTable[i] = NULL;
  }
}

void rehash(LinkedList** &hashTable, int &tableSize){
  int newSize = (tableSize * 2) - 1;
  LinkedList** newTable = new LinkedList*[newSize];
  nullify(newTable, newSize);
  for(int i = 0; i < tableSize; i++){
    if(hashTable[i] != NULL){
      Node* current = hashTable[i]->getHead();
      while(current != NULL){
	int id = current->getStudent()->getID();
	int newIndex = hashbrown(id, newSize);
	if(newTable[newIndex] == NULL){
	  newTable[newIndex] = new LinkedList();
	}
	bool reHash = false;
	Node* newNode = new Node(new Student(current->getStudent()));
	newTable[newIndex]->add(newNode, reHash);
	current = current->getNext();
      }
    }
  }
  for (int i = 0; i < tableSize; i++) {
    delete hashTable[i];
  }
  delete[] hashTable;
  hashTable = newTable;
  tableSize = newSize;
}
