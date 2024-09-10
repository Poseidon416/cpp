#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cctype>

using namespace std;

/*Nikhil Mantha
 *C++ & Data Structures
 *Guessing Game
 */

/*
 * 3 Rules of C++
 * NO STRINGS 
 * NO GLOBAL VARIABLES
 * NO BREAK/CONTINUE UNLESS SWITCH
 */

int main(){
  //Generate random num:
  srand(time(NULL));
  int num = 1 + rand() % 100;
  
  cout << "Welcome to guessing game! Enter a number between 1-100" << endl;

  int guesses = 0; //Keep track of guesses
  while (true) {
    guesses++; //increment guess count
    cout << "Enter a number: ";
    int input;
    if (cin >> input) {
      if (input == num) { //checks if user guessed correctly
	cout << "Correct! It took you " << guesses << " guess(es).\nWould you like to play again? (Y/N): ";
	char play_again[2];
	cin >> play_again; //asks if user wants to play again
	play_again[0] = (char) tolower(play_again[0]);
	if(strcmp(play_again, "y") == 0) { //if yes, restart program
	  main(); 
	} else{ //if no, exit game
	  exit(0);
	}
      } else if (input > num) { //guess is too high
	cout << "Too high." << endl;
      } else { //guess is too low
	cout << "Too low." << endl;
      }
    } else {
      cout << "Please enter numbers only." << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }  
  }
  return 0;
}
