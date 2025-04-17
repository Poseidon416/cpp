#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void add(int* &heap);

int main(){
  cout << "\033[H\033[2J"; //clear console

  cout << "\033[4m\033[1m" << "\t\t\tHEAP" << "\033[0m" << endl;
  cout << "\033[1m" << "-------------------------------------------------------" << endl;
  cout << " Commands: \"ADD\", \"FILE\", \"PRINT\", \"DELETE\", \"QUIT\"" << endl;
  cout << "-------------------------------------------------------" << "\033[0m" << endl;

  int* heap = new int[100];
  for (int i = 0; i < 100; i++) {
    heap[i] = NULL;
  }
  
  bool running = true;
  while (running){
    // takes user input for command
    string command;
    cout << "Enter command: ";
    cin >> command;
    cin.ignore();
    
    if (command == "ADD") { //adds a student to the linked list
      cout << "\033[1m-------- ADD --------\033[0m" << endl;
      
      cout << "\033[1m-------- END --------\033[0m" << endl;
    } else if (command == "FILE") { //adds 250 random students from a file
      //fstream file("numbers.txt");
      
      //file.close();
    } else if (command == "PRINT") { // prints all students currently in list

      cout << "\033[1m--------------------------\033[0m" << endl;
    } else if (command == "DELETE") { // deletes student based on their ID
      cout << "\033[1m-------- DELETE --------\033[0m" << endl;
      
      cout << "\033[1m------------------------\033[0m" << endl;
    } else if (command == "QUIT") {
      running = false; //ends while loop
    } else {
      cout << "That command doesn't exist." << endl;
    }
  }
  delete[] heap;
  return 0;
}

void sort(int* &heap) {
  
}
