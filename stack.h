#ifndef STACK_H
#define STACK_H
#include <string>

using namespace std;


//max before class
const int MAX = 30; // changing stack to 30 for num conversion
typedef char el_t; // needs to be before the stack class

class Stack
{

 private:
  el_t arrayStack[MAX];
  int top; //int top =-1
  void stackError(string);
 public:
  
  Stack();
   bool isEmpty();
   void addPerson();
   bool isFull() const;
   void push (el_t e);
   el_t pop();
   el_t topElem();
   void displayAll();
   void clearIt();
   
};




#endif
