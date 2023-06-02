#include "lqueue.h"
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

//default constructor
LQueue::LQueue(){
  front = NULL;// initializing front to NULL, indicated the queue is empt 
  rear = NULL;// initializing rear to NULL, indicates the queue is empt 
  count = 0;

}

//adds a node at the rear 
void LQueue::addRear(el_t el)
{

  //if linked list is empty
  if(isEmpty())
    {
      front = new node; //making a new node
      rear = front;//rear and front point to same node

  }else{
    rear->next = new node; // rear is now temp
    rear = rear-> next;// making rear point to the next node

  }
  rear->next = NULL; //rear is now null                                                                                            
  rear-> elem = el; //rear points to  
  count++; // incrememnt counter
  
}

void LQueue::queueError(string msg)
{
  cout << msg << endl;
  exit(1);
}

bool LQueue::isEmpty() const
{
  if(front == NULL && rear == NULL && count == 0)
    {
      return true;
    }else{
    return false;
  }
}

void LQueue::displayAll() 
{
  //making a new pointer named p
  
  //p = front;
  if(isEmpty())
    {
      cout << "empty!" << endl;
    }else
    {
      node* p = front;
      while(p!= NULL) //makes sure p visits each node
	{
	  //print the element pointed to by p
	  cout << (*p).elem << " ";
	  p = p->next; //moving p to the next node
	} 
    }
}

el_t LQueue::deleteFront()
{
  el_t temp;
  if(isEmpty()){ //if no nodes
    queueError("Error. list is empty"); //caling queueerror
    
  }
  else {
    node* second = front->next; // make a second  pointer
    el_t temp = (*front).elem;
    delete front; //remove front pointer
    front = second; // second now has fronts node
    if(count == 1) //if count is 1 temp,front and rear = NULL                                  
      {
	rear = front; // making rear                                                           

      }
    count--;
    return temp;
  }

}

void LQueue::printAllReverse()
{
  printAllReverse(front);
}

void LQueue::printAllReverse(node* p)
{
  if(p==NULL)
    {
      return;
    }else{
    printAllReverse(p->next);
    cout << p->elem;
  }
}

LQueue::~LQueue()
{
  while(!isEmpty())
    {
      deleteFront();
    }
}
