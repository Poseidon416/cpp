#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/*Nikhil Mantha
 *C++ & Data Structures
 *Tic Tac Toe
 */

void print_board(const char board[3][3], int xscore, int oscore);
void reset_board(char board[3][3]);
void format_coords(const char coords[3], int &row, int &col);
bool is_valid_move(const char board[3][3], int row, int col);
void place_player(char board[3][3], char player, int row, int col);
void take_turn(char board[3][3], char player);
bool check_win(const char board[3][3], char player);
bool check_tie(const char board[3][3]);

int main() {
  char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
  char player = 'X';
  bool game = true;
  bool playing = true;
  int xscore = 0;
  int oscore = 0;
  
  print_board(board, xscore, oscore);

  while (game) {
    while (playing) {
      take_turn(board, player);
      print_board(board, xscore, oscore);
      if (check_win(board, player)) {	
	print_board(board, xscore, oscore);
	cout << "\033[1m" << player << " Wins!" << "\033[0m" << endl;
	playing = false;
	if (player == 'X') { xscore++; } else { oscore ++; }
	cout << "\033[1m" << "Score = " << "\033[0m" << "X:" << xscore << " - O:" << oscore << endl;
      } else if (check_tie(board)) {
	print_board(board, xscore, oscore);
	cout << "\033[1m" << "It's a tie." << "\033[0m" << endl;
	playing = false;
	cout << "\033[1m" << "Score = " << "\033[0m" << "X:" << xscore << " - O:" << oscore << endl;
      }
      if (!playing) {
	char input[2];
	cout << "Play again? (y/n): ";
	cin >> input;
	if(input[0] == 'y' || input[0] == 'Y') {
	  playing = true;
	  reset_board(board);
	  print_board(board, xscore, oscore);
	} else {
	  game = false;
	}
      }
      player = (player == 'X') ? 'O':'X';
    }
  }
  return 0;
}

void print_board(const char board[3][3], int xscore, int oscore) {
  cout << "\033[H\033[2J";

  cout << "\t  " << "\033[4m\033[1m" << "Tic Tac Toe" << "\033[0m" << endl;
  cout << "\t   X:" << xscore << " - O:" << oscore << endl << endl;
  cout << "\t    1   2   3" << endl << endl;
  for ( int row = 0; row < 3; row++ ) {
    char letter = 'a' + row; //adds ascii, so 'a' (97) + 1 = 98 which is 'b'
    cout << '\t' << letter << "   ";
    for ( int column = 0; column < 3; column++ ) {
      cout << board[row][column] << "   ";
    }
    cout << endl << endl;
  }
}

void reset_board(char board[3][3]) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      board[row][col] = '-';
    }
  }
}

void format_coords(const char coords[3], int &row, int &col){
  row = coords[0] - 'a';
  col = coords[1] - '1';
}

bool is_valid_move(const char board[3][3], int row, int col) {
  return (row >= 0 && row < 3) && (col >=0 && col < 3) && board[row][col] == '-';
}

void place_player(char board[3][3], char player, int row, int col) {
  board[row][col] = player;
}

void take_turn(char board[3][3], char player) {
  bool valid = false;
  char coords[3];
  while (!valid){
    cout << "Enter a coordinate: ";
    cin >> coords;
    if (isalpha(coords[0]) && isdigit(coords[1]) && coords[2] == '\0') {
      int row, col;
      format_coords(coords, row, col);
      if(is_valid_move(board, row, col)) {
	valid = true;
	place_player(board, player, row, col);
      } else {
	cout << "Please enter a valid coordinate (e.g., \"a1\")." << endl;
      }
    } else {
      cout << "Please enter a valid coordinate (e.g., \"a1\")." << endl;
    }
  }
}

bool check_win(const char board[3][3], char player) {
  for(int row = 0; row < 3; row++) {
    if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
      return true;
    }
  }

  for(int col = 0; col < 3; col++) {
    if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
      return true;
    }
  }

  if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player && board[2][0] == player)){
    return true;
  }

  return false;
}

bool check_tie(const char board[3][3]) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (board[row][col] == '-') {
	return false;
      }
    }
  }
  return true;
}
