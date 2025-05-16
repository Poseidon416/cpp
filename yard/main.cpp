#include <iostream>
#include <string>
#include <cctype>
#include "Stack.hpp"
#include "Queue.hpp"
#include "TNode.hpp"

using namespace std;

string shuntingYard(string infix);

int main(){
  cout << "\033[4m\033[1m\tShunting Yard Algorithm\033[0m" << endl;
  
  string input;
  cout << "Enter an equation (+,-,*,/):  ";
  getline(cin, input);
  shuntingYard(input);

  return 0;
}

string shuntingYard(string infix) {
  Queue* output = new Queue();
  Stack* operators = new Stack();

  int start = -1;
  int count = 0;
  for (int i = 0; i < infix.length(); i++) {
    char c = infix.at(i);
    if (isdigit(c)) {
      if(start == -1) {
	start = i;
	count = 1;
      } else {
	count++;
      }
    } else {
      if (start != -1) { //there is a sequence of digits
	string s = infix.substr(start, count);
	cout << s << endl;
	start = -1;
	count = 0;
      }
      if (!isspace(c)) {
	cout << c << endl;
      }
    }
    //if last char is a digit
    if (start != -1) {
      string s = infix.substr(start, count);
      cout << s << endl;
    }
  }
  return "";
}


