#include <iostream>
#include <string>
#include <cctype>
#include "Stack.hpp"
#include "Queue.hpp"
#include "TNode.hpp"

using namespace std;

/* sources:
 * https://en.wikipedia.org/wiki/Shunting_yard_algorithm
 * https://en.wikipedia.org/wiki/Binary_expression_tree
 */

bool isOperator(char op);
bool isOperator(string op);
int operatorRank(char op);
string assosciation(char op);

Queue<string>* shuntingYard(string infix);
TNode<string>* expressionTree(Queue<string>* postfix);
void printTree(TNode<string>* root, int depth = 0);

int main(){
  cout << "\033[4m\033[1m\tShunting Yard Algorithm\033[0m" << endl;
  
  string input;
  cout << "Enter an equation (+,-,*,/,^): ";
  getline(cin, input);
  Queue<string>* postfix = shuntingYard(input);
  if(postfix->isEmpty()) {
    cout << "Enter valid expression.";
    exit(1);
  }
  TNode<string>* root = expressionTree(postfix);
  cout << "Post-fix: ";
  while(!postfix->isEmpty()){
    cout << postfix->dequeue() << " ";
  }
  cout << "Tree:" << endl;
  printTree(root);
  return 0;
}

bool isOperator(char op) {
  return op == '+' || op == '-' || op == '*' || op == '/' || op == '^';
}

bool isOperator(string op) {
  return isOperator(op[0]);
}

int operatorRank(string op) {
  if (op == "^") {
    return 4;
  } else if (op == "*" || op == "/") {
    return 3;
  } else if (op == "+" || op == "-") {
    return 2;
  } else {
    return 0;
  }  
}

string assosciation(char op) {
  if (op == '^') {
    return "RIGHT";
  }
  return "LEFT";
}

Queue<string>* shuntingYard(string infix) {
  Queue<string>* output = new Queue<string>();
  Stack<string>* operators = new Stack<string>();

  int start = -1;
  int count = 0;
  for (int i = 0; i < infix.length(); i++) {
    char c = infix[i];
    if (isdigit(c)) {
      if(start == -1) {//checks if there is no current num sequence
	start = i;
	count = 1;
      } else { //if there is a sequence, increases digit count
	count++;
      }
    } else { //if not a digit
      if (start != -1) { //completes num sequence and resets
	string s = infix.substr(start, count);
	output->enqueue(s);
	start = -1;
	count = 0;
      }
      if (isOperator(c)) {
	string s(1, c);
	while (!operators->isEmpty() && operators->peek() != "(" && (operatorRank(operators->peek()) >
	operatorRank(s) || (operatorRank(operators->peek()) == operatorRank(s) && assosciation(c) == "LEFT"))) {
	  output->enqueue(operators->pop());
	}
	operators->push(s);
      } else if (c == '(') {
	string s(1, c);
	operators->push(s);
      } else if (c == ')') {
	while (!operators->isEmpty() && operators->peek() != "(") {
	  output->enqueue(operators->pop());
	}
	if (operators->isEmpty()) {
	  cout << "Error: Mismatched parentheses." << endl;
	  exit(1);
	}
	operators->pop();
      }
    }
  }
  //if last char is a digit
  if (start != -1) {
    string s = infix.substr(start, count);
    output->enqueue(s);
  }
  //empty operator stack into output
  while(!operators->isEmpty()) {
    if (operators->peek() == "(" || operators->peek() == ")") {
      cout << "Error: Mismatched parentheses." << endl;
      exit(1);
    }
    output->enqueue(operators->pop());
  }

  return output;
}

TNode<string>* expressionTree(Queue<string>* postfix) {
  Stack<TNode<string>*>* trees = new Stack<TNode<string>*>();
  while(!postfix->isEmpty()){
    string s = postfix->dequeue();
    TNode<string>* t = new TNode<string>(s);
    if (!isOperator(t->getVal())) {
      trees->push(t);
    } else {
      t->setRight(trees->pop());
      t->setLeft(trees->pop());
      trees->push(t);
    }
  }
  return trees->pop();
}

void printTree(TNode<string>* curr, int depth) {
  if (curr == NULL) return;

  printTree(curr->getRight(), depth + 1);
  
  for(int i = 0; i < depth; i++) {
    cout << '\t';
  }
  cout << curr->getVal() << endl;

  printTree(curr->getLeft(), depth + 1);
}
