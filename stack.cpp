#include "stack.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

Stack::Stack ()
{
  top = -1;
}
bool Stack:: isEmpty(){
  if(top == -1){
    return true;
   }
 return false;
}

el_t Stack:: topElem()
{
  el_t e;
 e = arrayStack[top];
 return e;
}
// pop is removing 
el_t Stack::pop(){
  el_t tempPopContainer;

  if (isEmpty()){
    stackError("stack overflow");
  }

  tempPopContainer = arrayStack[top];
  top--;
  return tempPopContainer;
}


void Stack::displayAll(){
  //if empty we print empty
  if (isEmpty()){
    cout << "empty" << endl;
  }else{
    //loop thru array and print the stack 
    //arraystack is the array that represents the stack!
    for (int i = top; i >= 0; i--){
      cout << arrayStack[i] << endl;
    }
  }
}

void Stack::clearIt(){
  el_t tempPopContainer; //temp local var that holds elements from top
  
  while (!isEmpty()){
    tempPopContainer = pop();
  }
}

void Stack::stackError(string msg){
  cout << msg << endl;
  exit(1); //this ends program. 1 is returned to the operating system. 0 = end with no error, 1 = end w/errors. 
  //include cstdlib
}

//const is full
//conditional operator , true if full, false if not
bool Stack::isFull() const
{
  if(top == MAX - 1){
    return true;
   }
  return false;
  // return (top == -1)? true:false;
}
//push is the samee as adding to the stack
void Stack::push (el_t e){
  //if stack is full display an error message
  if (isFull())
    {
      stackError("stack overflow");
    } else {
    top++;
    arrayStack[top] = e;
   
       }
}


