#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/*Nikhil Mantha
 *C++ & Data Structures
 *Tic Tac Toe
 */

void print_board(char (&board)[3][3]);


int main() {
  char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
  char player = 'X';
  bool playing = true;
  
  print_board(board);

  
  return 0;
}

void print_board(char (&board)[3][3]) {
  cout << "\033[H\033[2J";

  cout << "\t  " << "\033[4m\033[1m" << "Tic Tac Toe" << "\033[0m" << endl << endl;
  cout << "\t    1   2   3" << endl << endl;
  char letters[4] = "abc";
  for ( int row = 0; row < 3; row++ ) {
    cout << '\t' << letters[row] << "   ";
    for ( int column = 0; column < 3; column++ ) {
      cout << board[row][column] << "   ";
    }
    cout << endl << endl;
  }
}
