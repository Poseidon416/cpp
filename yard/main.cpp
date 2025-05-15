#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(){
  Queue* s = new Queue();
  string v = s->pop();
  cout << v << endl;
  s->push("1");
  cout << s->pop() << endl;
  s->push("1");
  s->push("2");
  cout << s->pop() << endl;
  cout << s->pop() << endl;
  
  
  return 0;
}
