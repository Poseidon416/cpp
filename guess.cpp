#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
  //generate random num
  srand(time(NULL));
  int num = 1 + rand() % 100;
  
  cout << "Welcome to guessing game! Enter a number between 1-100" << endl;

  int guesses = 0;
  while (true) {
    guesses++;
    cout << num << endl;
    cout << "Enter a number: ";
    int input;
    cin >> input;
    if (input == num) {
      cout << "Correct! It took you " << guesses << " guess(es).\nWould you like to play again? (Y/N): ";
      char play_again[2];
      cin >> play_again;
      if(strcmp(play_again, "Y") == 0) {
	main();
      } else{
	exit(0);
      }
    }
  }
  return 0;
}
