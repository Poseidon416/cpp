#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//function declarations
void add(int* &heap, int &size, int num);
void sortUp(int* &heap, int start);
void sortDown(int* &heap, int start, int size);
void print(int* heap, int curr, int depth, int size);

int main(){
  cout << "\033[H\033[2J"; //clear console

  cout << " \033[4m\033[1m" << "\t\t\tHEAP" << "\033[0m" << endl;
  cout << "\033[1m\033[7m" << "---------------------------------------------------------" << endl;
  cout << " CMDS: \"ADD n\", \"FILE\", \"PRINT\", \"ROOT\", \"ROOT*\", \"QUIT\" " << endl;
  cout << "---------------------------------------------------------" << "\033[0m" << endl;

  int* heap = new int[100];
  for (int i = 0; i < 100; i++) { //initializes array to null
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

      int num;
      cin >> num;
      add(heap, size, num);

    } else if (command == "FILE") { //adds numbers from a file

      fstream file("numbers.txt");
      string num;
      while (getline(file, num, ' ')) {
	add(heap, size, stoi(num));
      }
      file.close();
      
    } else if (command == "PRINT") { // prints heap

      cout << "\033[1m---------------------\033[0m" << endl;
      cout << "\033[4m\033[1mHeap:\033[0m" << endl;
      
      print(heap, 0, 0, size);

      cout << "\033[1m---------------------\033[0m" << endl;

    } else if (command == "ROOT") { //prints root and removes from heap

      size -= 1;
      cout << "Root: " << heap[0] << endl;
      heap[0] = heap[size]; //replaces root with right-most leaf
      heap[size] = NULL;
      sortDown(heap, 0, size); //recursively sorts down the tree

    } else if (command == "ROOT*") { // prints all roots one by one until heap is empty

      cout << "\033[1m-------- ROOT* --------\033[0m" << endl;
      while (size > 0){ //root command but repeated for all numbers in heap
	size -= 1;
	cout << heap[0];
	if (size >= 1){
	  cout << ", ";
	} else {
	  cout << endl;
	}
	heap[0] = heap[size];
	heap[size] = NULL;
	sortDown(heap, 0, size);
      }
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
  heap[size] = num; //adds number to next open slot
  sortUp(heap, size); //sorts up recursively
  size++; 
}

void sortUp(int* &heap, int start) {
  int parentIndex = floor((start-1)/2);
  
  int child = heap[start];
  int parent = heap[parentIndex];
  if (child > parent){ //swap child with parent
    heap[start] = parent;
    heap[parentIndex] = child;
    sortUp(heap, parentIndex); //recurse up to the parent
  }
}

void sortDown(int* &heap, int start, int size){
  int largest = start;
  int left = start*2 + 1; 
  int right = start*2 + 2;

  //finds the largest out of parent, left child, and right child
  if (left < size && heap[left] > heap[largest]) {
    largest = left;
  }
  if (right < size && heap[right] > heap[largest]) {
    largest = right;
  }
  
  //swaps with largest child if there is one
  if (largest != start){
    int temp = heap[start];
    heap[start] = heap[largest];
    heap[largest] = temp;
    sortDown(heap, largest, size);
  }
}

void print(int* heap, int curr, int depth, int size){
  if (size == 0) { return; } //doesn't print if heap empty
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
