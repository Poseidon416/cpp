#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int hashbrown(int id, int tableSize);
void fillna(LinkedList* hashTable[], int tableSize);
void insert();

int main(){
  cout << "\033[H\033[2J"; //clear console

  cout << "\033[4m\033[1m" << "\t\tWELCOME TO STUDENT LIST" << "\033[0m" << endl;
  cout << "\033[1m" << "-------------------------------------------------------" << endl;
  cout << " Commands: \"ADD\", \"PRINT\", \"DELETE\", \"QUIT\"" << endl;
  cout << "-------------------------------------------------------" << "\033[0m" << endl;

  int tableSize = 101;
  LinkedList** hashTable = new LinkedList*[tableSize];
  fillna(hashTable, tableSize);

  bool running = true;
  while (running){
    // takes user input for command
    char command[10];
    cout << "Enter command: ";
    cin >> command;
    
    if (strcmp(command, "ADD") == 0) { //adds a student to the linked list
      cout << "\033[1m-------- ADD --------\033[0m" << endl;
      Node* n = new Node();
      int id = n->getStudent()->getID();
      index = hashbrown(id, tableSize);
      if(hashTable[index] == NULL) {
	hashTable[index] == new LinkedList();
      }
      bool reHash = false;
      hashTable[index]->add(n, reHash);
      cout << "\033[1m-------- END --------\033[0m" << endl;
    } else if (strcmp(command, "PRINT") == 0) { // prints all students currently in list
      cout << "\033[1m-------- STUDENTS --------\033[0m" << endl;
      //print
      cout << "\033[1m--------------------------\033[0m" << endl;
    } else if (strcmp(command, "DELETE") == 0) { // deletes student based on their ID
      cout << "\033[1m-------- DELETE --------\033[0m" << endl;
      //delete
      cout << "\033[1m------------------------\033[0m" << endl;
    } else if (strcmp(command, "QUIT") == 0) {
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

void fillna(LinkedList* hashTable[], int tableSize){
  for(int i = 0; i < tableSize; i++){
    hashTable[i] = NULL
  }
} 
