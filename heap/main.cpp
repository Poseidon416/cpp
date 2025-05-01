#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void add(int* &heap, int &size, int num);
void sort(int* &heap, int start);
void print(int* heap, int curr, int depth, int size);

int main(){
  cout << "\033[H\033[2J"; //clear console

  cout << "\033[4m\033[1m" << "\t\t\tHEAP" << "\033[0m" << endl;
  cout << "\033[1m" << "-------------------------------------------------------" << endl;
  cout << " Commands: \"ADD\", \"FILE\", \"PRINT\", \"ROOT\", \"DELETE\", \"QUIT\"" << endl;
  cout << "-------------------------------------------------------" << "\033[0m" << endl;

  int* heap = new int[100];
  for (int i = 0; i < 100; i++) {
    heap[i] = NULL;
  }
  
  bool running = true;
  int size = 0;
  while (running){
    // takes user input for command
    string command;
    cout << "Enter command: ";
    cin >> command;
    cin.ignore();
    
    if (command == "ADD") { //adds a number to the heap
      cout << "\033[1m-------- ADD --------\033[0m" << endl;
      int num;
      cout << "Enter integer: ";
      cin >> num;
      add(heap, size, num);
      cout << "\033[1m---------------------\033[0m" << endl;
    } else if (command == "FILE") { //adds numbers from a file
      fstream file("numbers.txt");
      string num;
      while (getline(file, num, ' ')) {
	add(heap, size, stoi(num));
      }
      file.close();
    } else if (command == "PRINT") { // prints heap
      print(heap, 0, 0, size);
      cout << "\033[1m--------------------------\033[0m" << endl;
    } else if (command == "ROOT") {
      cout << "Root: " << heap[0] << endl;
      heap[0] =
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

void add(int* &heap, int &size, int num) {
  if (size == 99) { //table full
    cout << "Heap is now full." << endl;
    return;
  }
  heap[size] = num;
  sort(heap, size);
  size++;
}

void sort(int* &heap, int start) {
  int parentIndex = floor((start-1)/2);
  
  int child = heap[start];
  int parent = heap[parentIndex];
  if (child > parent){
    heap[start] = parent;
    heap[parentIndex] = child;
    sort(heap, parentIndex);
  }
}

void print(int* heap, int curr, int depth, int size){
  if (curr*2 + 2 < size) {
    print(heap, curr*2 + 2, depth+1, size);
  }
  for (int i = 0; i < depth; i++) {
    cout << '\t';
  }
  cout << heap[curr] << endl;
  if (curr*2 + 1 < size) {
    print(heap, curr*2 + 1, depth+1, size);
  }
}
