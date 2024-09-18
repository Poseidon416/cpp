#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/*Nikhil Mantha
 *C++ & Data Structures
 *Palindrome
 */

int main() {
  cout << "Enter string: ";
  char str[80];
  cin.get(str, 80);
  cin.get();

  //removes punctuation and whitespace
  char trimmed[80];
  int count = 0;
  for (int i = 0; i < strlen(str); i++){
    if(isalpha(str[i])) { //checks if char is alphabetic
      trimmed[count] = str[i]; //adds to new cstring
      count++;
    }
  }
  trimmed[count] = '\0'; //adds terminating char to end cstring

  //reverses cstring
  char reversed[80];
  int i = 0;
  for(i; i < strlen(trimmed); i++){
    reversed[i] = trimmed[strlen(trimmed)-(i+1)];
  }
  reversed[i] = '\0';

  //compares strings to see if palindrome
  if (strcmp(trimmed, reversed) == 0) {
    cout << "\"" << trimmed << "\"" << " is a palindrome." << endl;
  } else {
    cout << "\"" << trimmed << "\"" << " is NOT a palindrome." << endl;
  }
  
  return 0;
}
