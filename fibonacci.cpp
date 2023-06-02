
#include <iostream> 
#include <time.h> 
using namespace std; 
#include "/cs/slott/cs211/checkInput.h" 
 

int fib1(int pos)
{

  if(pos <= 1){
    return pos;
  }else {
    return( fib1(pos - 2) + fib1(pos - 1));
  }
}

//non recursive function                                                        
int fib2(int pos){                                                              
                                                                                
 int n1 = 0;
 int n2 = 1;
 int n3 = pos;
 //i = po s & pos--, goes down everytime u get out loop
 for (int i = pos; i > 0; i--){                                                
   int temp = n2; 
   n2 = n1 + n2;
   n1  = temp;                                                                                
  }                                                                             
}                                                                              
int main() 
{ 
  int pos; 
  clock_t start, end;  
 
  
  cout << "Enter a position: "; 
  pos = getData(0, 46, "Invalid input. Please enter a position between 0 and 46"); 
  int fibNum = fib1(pos);
  //start  timing 
  start = clock();  // clock() returns the number of clock ticks elapsed since the beginning of the program execution 

  // Call fib1 with pos or  Call fib2 with pos  
  cout << fib1(pos);
  
  //stop timing 
  end = clock();   
 
 cout << "Elapsed time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl; 
 // CLOCKS_PER_SEC is the number of clock ticks per second 
 
 cout << "Fibonnaci number at position " << pos << " is " << fibNum << endl; 
 
 return 0; 

} 

