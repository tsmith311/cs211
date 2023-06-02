#include "DLL.h"
#include <cstdlib>
#include <iostream>

using namespace std;

//default constructor
DLL::DLL(){
  front = NULL;// initializing front to NULL, indicated the queue is empt 
  rear = NULL;// initializing rear to NULL, indicates the queue is empt 
  count = 0;

}


//adds a node at the rear 
void DLL::addRear(el_t el)
{

  //if linked list is empty
  if(isEmpty())
    {
      front = rear = new node; //making a new node
      front->prev = NULL; //front ->prev is NULL
  }else{
    rear->next = new node; // rear is now temp
    rear->next->prev = rear; //
    rear = rear->next; 
  }

  rear->next = NULL; //rear points to nothing since its the last no
  rear->elem = el; //whatever user inputs goes into rear
  count++; // incrememnt counter
  
}

void DLL::addFront(el_t el)
{
  //check if empty
  if(front == NULL){
    front = rear = new node; // if empty front makes a new node
    //    front->prev = NULL;

  }else{
    front->prev = new node; //making a new node in front 
    front->prev->next = front; //make it point to front
    front = front->prev; // front is  prev(like our temp)
    }
  front->prev = NULL; // f->prev is null
  rear->next = NULL; //rear points to nothing since last node
   front->elem = el; //whatever the user inputs goes in the frornt
  
  count++; //incrememnt counter
}
//fix
void DLL::printAllReverseDLL()
{
  node* p = rear;
  if(isEmpty())
    {
      cout << "empty!";
    }else{
    
    while(p != NULL) 
      {
	cout << p->elem << " ";
	
	p = p->prev; //moving p through link list
	//	cout << p->elem; 
	//	rear = rear->next; // 
      } 
    //start and print from rear using prev pointer
  }
}

void DLL::queueError(string msg)
{

  cout << msg << endl;
   exit(0);
}

bool DLL::isEmpty() const
{
  if(front == NULL && rear == NULL && count == 0)
    {
      return true;
    }else{
    return false;
  }
}

DLL::~DLL()
{
  while(!isEmpty())
    {
      deleteFront();
    }
}
void DLL::displayAll() 
{
  //p = front;
  if(isEmpty())
    {
      //      queueError("[empty]");
     cout << "[empty]" << endl;
    }else {
    node* p = front;
    while(p!= NULL) //makes sure p visits each node
      {
	//print the element pointed to by p
	cout << (*p).elem << " ";
	p = p->next; //moving p to the next node
      } 
  }
}

el_t DLL::deleteFront()
{  
  el_t temp;
  if(count == 1)
    {
      temp = (*front).elem;
      delete front; // del                                                           
      front->prev = rear->next = NULL;
      rear = NULL;
      front = NULL;
      count--;
      return temp;
    }
  else if(isEmpty()){ //if no nodes
    cout << "[empty]";
    //queueError("Error. list is empty"); //caling queueerror
  }
  else
    {
      node* p = front->next; // make a second  pointer
      //temp =front->elem; // temp gets the front elem
       temp = (*front).elem; // temp gets the fronts elem(contents)
      delete front; //remove front pointer
      front = p; // p now has fronts node
      front->prev = NULL; // f prev is null
      count--; 
      return temp;                                                                     
    }                   
  
}


el_t DLL::deleteRear()
{
  el_t temp; // make a temp
  if(count == 1)
    {
      temp = rear->elem;
      delete rear;
      front->prev= rear->next = NULL;
      front = NULL;
      rear = NULL;
      count--;
      return temp;

    }
  else if(isEmpty())
    {
      cout << "[empty]";
      //queueError("Error: list is empty!"); //call queueError if empty
    }
 
   else 
    {
      node* p = rear->prev; // make a new node called p and have it point to rear's prev
      temp = rear->elem;
      //      temp = (*rear).elem;
      delete rear;
      rear = p; //making rear point to p now
      rear->next = NULL; //rear is NULL
      count--;
      return temp;
       
    }
}

bool DLL::search(el_t e)
{
  node* el = front;
 
  while(el != NULL) //to make sure p visits every node
    {
      if(el->elem == e) //if theres a match
	{
	  return true; // true
	  //	  el = el->next;
	}
      el = el->next;
    }
  return false; //else is false 0
   
}


void DLL::deleteNode(el_t e)
{
  node* pre; //node before the delete                                                                                                     
  node* del; //for what we want to delete 
  if(isEmpty())
    { //if empty
       cout << "Empty." << endl;

    }
  else if(front->elem == e)
    {
      	  deleteFront(); //1 (for 1 node case) if its in the front call delete front 
    } 
  else
    {
      for( del= front->next; del!= NULL &&  del->elem!=e;del = del->next);
       if(del == NULL)
        {

        }
       else if(rear->elem == e)  // if rear                                                                    
	 {
	   deleteRear();
	 }
       else if(del->elem == e) //if del is in the middle
	 {

	   del->prev->next = del->next;
	   del->next->prev = del->prev; //this is to connect it back
	   delete del;
	   rear->next = NULL;
	  
	   count--;
	 }
    }
}
//extra credit
void DLL::addInOrderDescend(el_t e)
{


  if(isEmpty()) //if empty
    {
      addFront(e); //add front
    }
  else if(e > front->elem)  //if e is bigger than front 
    {
      addFront(e); // add e to front
    }
  else
    {
      node* p = front;
      
      while(p->next != NULL  && p->next->elem > e) // if e is smaller than p->next
	{
	  p = p->next;

	}
      node* temp = new node; 
      temp->elem = e; //temp is e 
      temp->next = p->next; 
      p->next = temp; //link if follows condition
      count++; //increment counter
    }

}
//fix
void DLL::addInOrderAscend(el_t e)
{
  node* p = front;
  node* temp = new node;
 
 //check if empty
  if(isEmpty())
    {
      addFront(e);
    }  
  else if(e < front->elem) // before first node, if ele is < first ele
    {
      addFront(e); //call addfront
    }
  else 
    {
      //    p = front;
    while(p->next != NULL && p->next->elem < e) // if e is bigger than p->next
      {
		
	p = p->next;
	//	new node->next = p->next;
      }	
      if(p->next != NULL)
	{
	  //	  node* temp = new node;//making temp node
	  temp->elem = e; //temp gets e
	  temp->next = p->next; 
	  temp->prev = p;
	  p->next = temp; // here we link if it followes the condtion
	  temp->next->prev = temp;
	  // temp->prev = NULL;
	  count++; //increment count
	}
      else
	{
	  rear->next = temp; 
	  temp ->prev = rear;
	  rear = temp;
	  rear->next = NULL;
	  rear->elem = e; //
	  count++; //increment count
	}
    }
}

DLL::DLL(const DLL& source)
{

  node*  p = source.front; // setting node pointer to the sources front
  this->front = this->rear = NULL; //beg. object has no elements in list                
  
  this->count = 0; // can be count = 0 or this->count = 0;                              
  
  while(p!= NULL) //visiting every node in the source                  
    {
      this-> addRear(p->elem); //copying the element in p from source                     
      
      p = p-> next; // moving to next element to copy                                         
      
    }
}
