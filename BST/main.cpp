#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.hpp"

using namespace std;

int main() {
  cout << "\033[H\033[2J"; //clear console

  cout << " \033[4m\033[1m" << "\t\tBINARY SEARCH TREE" << "\033[0m" << endl;
  cout << "\033[1m\033[7m" << "--------------------------------------------------" << endl;
  cout << " CMDS: \"ADD\", \"DELETE\", \"PRINT\", \"SEARCH\", \"QUIT\" " << endl;
  cout << "--------------------------------------------------" << "\033[0m" << endl;

  BinaryTree * bst = new BinaryTree();

  bool running = true;
  while (running) {
    // takes user input for command
    string command;
    cout << "Enter command: ";
    cin >> command;
    cin.ignore();
    
    if (command == "ADD") {
      cout << "--------------------------------------------------" << endl;
      cout << "Add from 1:Console, or 2:File? ";
      int response;
      cin >> response;
      if (response == 1) {
	cout << "Type 0 to quit" << endl;
	int i;
	while (true) {
	  cout << "Enter integer (1 - 999): ";
	  cin >> i;
	  if (i < 1 ) break;
	  bst->add(i);
	}
      } else {
	string fname;
	cout << "Enter file name: ";
	cin >> fname;
	fstream file(fname);
	string num;
	while (getline(file, num, ' ')){
	  bst->add(stoi(num));
	}
	file.close();
      }
      cout << "--------------------------------------------------" << endl;
    } else if (command == "DELETE") {
      cout << "--------------------------------------------------" << endl;
      int i;
      cout << "Enter integer to delete -> ";
      cin >> i;
      bst->erradicate(i);
      cout << "--------------------------------------------------" << endl;
    } else if (command == "SEARCH") {
      int i;
      cout << "Enter integer to search -> ";
      cin >> i;
      if(bst->search(i)){
	cout << i << " was found!" << endl;
      } else {
	cout << i << " was not found. :'(" << endl;
      }
    } else if (command == "PRINT") {
      cout << "--------------------------------------------------" << endl;
      bst->printTree();
      cout << "--------------------------------------------------" << endl;
    } else if (command == "QUIT") {
      running = false; //exits while loop
    } else {
      cout << "That command doesn't exist." << endl;
    }
  }
  return 0;
}
