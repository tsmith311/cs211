#include "LL.h"
#include <cstdlib>
#include <iostream>

using namespace std;

//default constructor
LL::LL(){
  front = NULL;// initializing front to NULL, indicated the queue is empt 
  rear = NULL;// initializing rear to NULL, indicates the queue is empt 
  count = 0;

}


//adds a node at the rear 
void LL::addRear(el_t el)
{

  //if linked list is empty
  if(count==0)
    {
      front = new node; //making a new node
      rear = front;//rear and front point to same node
  }else{
    rear->next = new node; // rear is now temp
    rear = rear-> next;// making rear point to the next node

  }
  rear->elem = el; //whatever user inputs goes into rear                      
  rear->next = NULL; //rear points to nothing since its the last no
  count++; // incrememnt counter
  
}

void LL::addFront(el_t el)
{
  //check if empty
  if(front == NULL){
    front = new node; // if empty front makes a new node
    rear = front; //rear and front point to the same new node
    rear->next = NULL; //rear points to nothing since last node
  }else{
    node* p = new node; //making a new node
    p->next = front; //make it point to front
    front = p; //p and front point to the same node now   
    }
  front->elem =el; //whatever the user inputs goes in the frornt
  
  count++;
}

void LL::queueError(string msg)
{

  cout << msg << endl;
   exit(0);
}

bool LL::isEmpty() const
{
  if(front == NULL && rear == NULL && count == 0)
    {
      return true;
    }else{
    return false;
  }
}

LL::~LL()
{
  while(!isEmpty())
    {
      deleteFront();
    }
}
void LL::displayAll() 
{
  //p = front;
  if(isEmpty())
    {
      //      cout << "empty!" << endl;
    }else {
    node* p = front;
    while(p!= NULL) //makes sure p visits each node
      {
	//print the element pointed to by p
	cout << " " << (*p).elem;
	p = p->next; //moving p to the next node
      } 
  }
}

el_t LL::deleteFront()
{  
  el_t temp;
  if(isEmpty()){ //if no nodes
    queueError("Error. list is empty"); //caling queueerror
  }
  else
    {
      node* p = front->next; // make a second  pointer
    temp = (*front).elem; // temp gets the fronts elem(contents)
    delete front; //remove front pointer
    front = p; // p now has fronts node    
    if(count == 1) //if count is 1 temp,front and rear = NULL	
      {
	rear = front;
      }
    
    count--;
    return temp;
    }
  
}


el_t LL::deleteRear()
{
  if(isEmpty())
    {
      queueError("Error: list is empty!"); //call queueError if empty
    }
  el_t temp = (*rear).elem;
  if(count == 1) // if there is one node only
    {
      delete rear; // delete rear
      front = rear = NULL; //front and rear are null

    }
  else
    {
      node* p; // make a new node called p
      for(p = front; p -> next != rear; p = p ->next); //this is for moving p 2nd to last we do nothing
      //      el_t temp = (*rear).elem; //temp gets rears element
      delete rear; // delete rear
      rear = p; //making rear point to p now
      rear -> next = NULL; //rear is NULL

    }
  count--;
  return temp;
}

bool LL::search(el_t e)
{
  node* el = front;
  int count = 0;
  while(el != NULL) //to make sure p visits every node
    {
      //      cout << ">" <<e <<"<"<< " >" << el->elem <<"<" << endl;
      count++;
      if(el->elem == e) //if theres a match
	{
	  //	  count++;
	  cout << count << endl;
          cout  << " nodes checked" << endl;
          cout << "found" << endl;
	  return true; // true
	  //	  el = el->next;
	}
      el = el->next;
    }


  //  cout << "hi" << endl;
  cout << count << endl;
  cout  << " nodes checked" << endl;
  cout << "NOT found" << endl;
  return false; //else is false 0
   
}


void LL::deleteNode(el_t e)
{
  node* pre; //node before the delete                                                    
  node* del; //for what we want to delete 
  if(isEmpty())
    { //if empty
       cout << "Empty." << endl;
      //       queueError("[empty]");
    }
  else if(front->elem == e)
    {
	  deleteFront(); // (for 1 node case) if its in the front call delete front
    }
  else
    {
      for(pre = front, del = front->next; del!= NULL &&  del->elem!=e; pre=del,del=del->next); //moving del, for if del is in the middle
      //while(del != NULL) 
  
       if(del == NULL)
        {
	  //	  cout << "does not exist." << endl;
	  //no nodes do nothing                                                          
        }
       else if(del->elem == e) //if del is in the middle
		{
		  pre->next = del->next;  //move pre to the node next to del
		  delete del;  //deletos
		  count--;
		}
      else if(rear->elem == e)  // if rear
	{
	  pre->next = NULL; //
	  del->next = NULL; //
	  rear = pre; //move pointers
	   delete del; // then delete 
	   count--; //decrement counter
	}
    }
}

void LL::addInOrderDescend(el_t e)
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

void LL::addInOrderAscend(el_t e)
{
  node* p = new node;
  
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
    p = front;
    while(p->next != NULL && p->next->elem < e) // if e is bigger than p->next
      {	
	p = p->next;
	//	new node->next = p->next;
	
      }
    node* temp = new node;//making temp node
    temp->elem = e; //temp gets e
    temp->next = p->next; 
    p->next = temp; // here we link if it followes the condtion
    
    count++; //increment count
  }
  /*
  else if(p != NULL && p->elem > e) //inserting in middle
     {
     
       count++;
       
       }*/
}



LL::LL(const LL& source)
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
