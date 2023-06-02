#include "lqueue.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;




//void createReverseLL(LQueue* , const string& );
void createReverseLL(LQueue &obj, const string& s)
{

  char ele;

  for(int i = s.size() - 1; i >= 0; i--) //when n is greater than/equal to 0, we continue looping
    {
      int temp; //holds the value for conversion
      ele = s[i];
      temp = (int)ele - '0'; //having temp hold chartoint
      obj.addRear(temp);

    }

}

void addLLs(LQueue& linkedList1, LQueue& linkedList2, LQueue& total) 
{
  int llElement1 = 0; // LL for first ele
  int llElement2 = 0; //LL for 2nd ele
  int sum;
  int leftover = 0; //"carry", can 


  while (!linkedList1.isEmpty() || !linkedList2.isEmpty()) {
    if (linkedList1.isEmpty()) { // if ll1 is empty
      llElement1 = 0; 
    }
    else {
      llElement1 = linkedList1.deleteFront(); //delete the front of linked list after you find sum
    }
    if (linkedList2.isEmpty()) {
      llElement2 = 0; // 
    }
    else {
      llElement2 = linkedList2.deleteFront(); 
    }
    sum = leftover + llElement1 + llElement2; // sum is the leftover (which can only be 1) eg:8 + 7, sum is 5 and carry is 1 since 8+7 is 15

    if (sum >= 10) { // if sum is bigger than 10
      sum = sum % 10; //using mod for condition to check if remainder
      leftover = 1; // leftover is 1 and gets added to the next node
    }
    else {
      leftover = 0; 
    }

    total.addRear(sum); // adding sum to the rear of total LL 
  }
  if (leftover > 0) { 
    total.addRear(leftover); //adding leftover to rear of total LL
  }
}

int main()
{

  string n1;
  string n2; //user input for long int

  cout << "Enter the first number: " << endl;
  cin >> n1;
  cout << "Enter the second number: " << endl;
  cin >> n2;
  
  cout << endl;
  LQueue l1; 
  LQueue l2;
  LQueue total;


  createReverseLL(l1,n1); //making 1st linked list for n1                           
  createReverseLL(l2,n2); //making 2nd linked list for n2 
  l1.displayAll(); //displaying n1
  cout << " + ";
  l2.displayAll();//displaying n2
  cout << " = ";
  addLLs(l1,l2,total);
  total.displayAll();

  
  
  cout << endl;
  createReverseLL(l1,n1); //making 1st linked list for n1                            
  
  createReverseLL(l2,n2); //making 2nd linked list for n2
  cout << endl;
  cout << n1 << " + " << n2 << " = ";
  total.printAllReverse();
  
  return 0;
 
 
}
