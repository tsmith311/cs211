#include "stack.h"
//#include "student.cpp"
#include <iostream>


void addPerson(Stack& s, string name)


{
  if(!s.isFull()){
    s.push(name);

  }else{
    cout << "You cant push. Stack is full." << endl;
  }
}

int main()
{
  Stack s;
  
 

  if (s.isEmpty()){
    cout << "The stack is empty." << endl;
  }

  addPerson(s, "Mike");
  addPerson(s, "Kathy");
 
  cout << s.topElem() << " is at the top." << endl;
  addPerson(s, "Dave");
  addPerson(s, "Alice");
  addPerson(s, "Tom");
  
  if (s.isFull()){
    cout << "The stack is full" << endl;
  } 
  s.displayAll();
  cout << s.topElem() << endl;
  addPerson(s, "Meg");
  s.pop();
  
  //  s.topElem();
  
  cout << s.topElem() << " is at the top." << endl << endl;
  s.clearIt();
  if (s.isEmpty()){
    cout << "The stack is empty." << endl << endl;
  }



}


