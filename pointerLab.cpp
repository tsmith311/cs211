#include <iostream>
using namespace std;

int main()
{
  /*
  int n =1;
  int* pi;
  double* pf1;
  double* pf2;
  string* ps;

  pi = &n;
  pf1 = new double;
  pf2 = new double;
  ps = new string;

  *pi = 2;
  *pf1 = 10.55;
  *pf2 = 11.55;
  *ps = "Hello";

  cout << "0" << pi <<endl;
  cout << "1" << pf1 << " " << pf2 << " " << ps << endl;
  cout << "2" << *pf1 << " " << *pf2 << " " << *ps << endl;
  
  delete ps;
  ps = new string;
  *ps = "World";
  
  cout << "3" << ps << endl;
  cout << "4" << *ps << endl;

  pf2 = pf1; 
 
  cout << "5 " << pf1 << " " << pf2 << endl; 
  cout << "6 " << *pf1 << " " << *pf2 <<  endl; 
 
  delete pf1; 
  pf1 = NULL; 
 
  cout << "7 " << pf1 << " " << pf2 << endl; 
  cout << "8 " << *pf2 <<  endl;

  cout << "9 " << *pf1 << endl; 
  */
  //declaring 2 pointers p1 and p2

  int* p1;
  int* p2;
  //cell with 1 in it
  
  //making p1 point to a cell 
  p1 = new int;
  *p1 = 1;

  //displaying cell content
  cout << *p1 << endl;
  
 
  //making p2 point to a cell
  p2 = new int;
  // putting 2 in cell
  *p2 = 2;
  //displaying cel content
  cout << *p2 << endl;
  //int n
  //deleting p2 cell before pointing to p1
  delete p2; 
  //making p2 point to same cell as p1
  p2 = p1;
  //displaying content of cell using p2
  cout << *p2 << endl;
  
  //initialize p1 to NULL
  p1 = NULL;//NULL = 0
  
  //making p2 point to a new cell
  p2 = new int;
  //put 3 in new cell
  *p2 = 3;
  //displaying cell content
  cout << *p2 << endl;
  
return 0
}
