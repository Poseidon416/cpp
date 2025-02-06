#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int hasher(int id, int tableSize);
void findIndex(LinkedList* hashTable[],int tableSize);

int main(){
  int tableSize = 101;
  LinkedList** hashTable = new LinkedList*[tableSize];

  Node* n = new Node();
  int id = n->getStudent()->getID();

  bool reHash = false;
  hashTable[hasher(id, tableSize)]->add(n, reHash);

  findIndex(hashTable, tableSize);
  return 0;
}

int hasher(int id, int tableSize){
  return id % tableSize;
}

void findIndex(LinkedList* hashTable[], int tableSize){
  for(int i = 0; i < tableSize; i++) {
    if(hashTable[i]->getHead() != NULL){
      cout << i;
    }
  }
}

