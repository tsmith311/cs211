#include "queue.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;


Queue::Queue ()
{
  front = 0;
  rear = -1;
  count = 0;
}

//returns true if empty otherwise false
bool Queue::isEmpty()
{
  if(count == 0 ){
    return true;
  }else{
  
    return false;
  }
}

bool Queue::isFull()
{
  if (count == QUEUE_SIZE)
    {
      return true;
    }
  return false;
}


void Queue::add(el_t e)
{  
  if (isFull())
    {
      queueError("queue is full");
    }else {
    
    rear = (rear+1) % QUEUE_SIZE; // increasing rear
    el[rear] = e;
    count++;
  }

}

el_t Queue::remove()
{

  if (isEmpty()){
    queueError("queue underflow");
    //    exit(1);
  }else{
    el_t r = el[front];
    front = (front + 1) % QUEUE_SIZE;
    count--;
    return r;
  }

}

void Queue::queueError(string msg)
{
  cout << msg << endl;
  //  exit(1);
}
ostream& operator<<(ostream& out, const expr& e)
{
  //show 5 + 8
  out << e.oprd1 << e.oprt << e.oprd2 << endl;
  return out;
}

void Queue::displayAll()
{
    /*
     cout << "[" << el[front] << "]" << " ";
  
	for (int i = front; i < count - 1; i++){
     cout << " " << el[(front + 1 + i) % QUEUE_SIZE] << " ";
	
    cout << "[" << el[rear] << "]" << endl;
	}
	
	}*/
  int index = front;
  for(int i = 0;i < count;i++){
    /*    cout << "[" << el[index] << "]" << " ";
    index = (index + 1) % QUEUE_SIZE;
  } 
  cout << endl;
    */
    cout << "[" << el[i] << "]";
  }
}
//accessing private member variables. just return front
el_t Queue::getFront()
{ 
  
  if(isEmpty()){

    exit(1);
  }
  else {

    return el[front];
  }
}

int Queue::getSize()
{

  return count; // for the size of queue 

}

//to move the front element to the rear
//use remove and add
void Queue::goToBack()
{
  if (isEmpty()){
    queueError("empty");
    // exit(1);
  }
  else if (count > 1){ //front and back are the same
    el_t temp; // temp for remove & add
    temp = remove(); //moves front(first element) to rear by calling the remove

    add(temp); //then adds to element in the back. 
    // front = (fro + 1) % QUEUE_SIZE;
    
  }

}
//front = (front +1) % QUEUE_SIZE
//rear = (rear+1) % QUEUE_SIZE
//i =(i+1) % QUEUE_SIZE 


