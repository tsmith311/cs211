#include <iostream>
using namespace std;
#include "array.h"  //This is your array.h
#include "rationalNumber.h"

rNum::rNum()
{
  top = 0;
  bottom = 1;
}
//default constructor: set top to 0 and bottom to 1
rNum::rNum(int t, int b)
{
  top = t;
  bottom = b;
}

ostream& operator<<(ostream& out,  rNum& p)
{
  // out << "" << p.top << "" << p.bottom;
  out  << p.top << "/" << p.bottom;
  return out;
}
istream& operator>>(istream& in, rNum& p)
{
  cout << "\n";
  cout << "Enter a top number:";
  in >>  p.top;
  cout << "\n";
  cout <<"Enter a bottom number:";
  in >> p.bottom;
  return in;
}

rNum operator+(const rNum& n, const rNum& q){
    
  rNum temp; // to hold the result which is a fraction
  //if the bottoms are equal just add the top and then return temp.
  if(n.bottom == q.bottom){
    temp.top = n.top + q.top;
    temp.bottom = n.bottom;
  }
  temp.top = (n.top * q.bottom) + (q.top * n.bottom);
  temp.bottom = (n.bottom * q.bottom);//this->bottom + n.top; load result with common denominator
    
  return temp;
}

//Create all operator overloaded functions here. You need to figure out what you need by reading the client.

// a += b means a = a + b | a-= b means a = a -b
// rhs means right hand side
void rNum::operator+=(const rNum& rhs)
{
  rNum temp; // to hold the result which is a fraction

  // we know the denominators are the same, so no need to cross multiply
  if (rhs.bottom == this->getBottom()) {
    temp.top = rhs.top + this->top;
    temp.bottom = this->getBottom();
  }
  //cross multipling
  this->setTop((rhs.top * this->getBottom()) + (rhs.bottom * this->getTop()));
  this->setBottom((this->getBottom() * rhs.bottom));
}

bool rNum::operator>(const rNum& rhs)
{
  rNum tempRhs = rhs;
  rNum tempLhs;
  //for lhs
  tempLhs.top = this->getTop(); 
  tempLhs.bottom = this->getBottom();
  // if the bottoms are the same
  if (tempRhs.bottom == this->getBottom()) {
    //3/4 > 1/4
    //compare the tops, in this case i made the lhs top greater
    if (this->top > tempRhs.top) {
      return true;
    }
    return false;
  }

  // 3/5 > 3/7
  int lhsTop = (tempRhs.top * tempLhs.bottom);
  int rhsTop = (tempRhs.bottom * tempLhs.top);
  int lhsBottom = (tempLhs.bottom * tempRhs.bottom);
  int rhsBottom = (tempLhs.bottom * tempRhs.bottom);
  tempLhs.top = lhsTop;
  tempLhs.bottom = lhsBottom;
  tempRhs.top = rhsTop;
  tempRhs.bottom = rhsBottom;
  if (tempLhs.top < tempRhs.top) {
    return true;
  }
  return false;
}

// this is for the 
bool rNum::operator==(const rNum& rhsKey) {
  rNum lhsTemp;
  lhsTemp.top = this->getTop();
  lhsTemp.bottom = this->getBottom();
  rNum rhsTemp;
  rhsTemp.top = rhsKey.top;
  rhsTemp.bottom = rhsKey.bottom;

  if (lhsTemp.top == rhsTemp.top && lhsTemp.bottom == rhsTemp.bottom) {
    return true;
  }
  return false;
}
//getters
int rNum::getTop() {
  return this->top;
}

int rNum::getBottom() {
  return this->bottom;
}
//setters
void rNum::setTop(int num) {
  this->top = num;
}

void rNum::setBottom(int num) {
  this->bottom = num;
}




//non-default constructor: we won't be using it in the client, but we might as well make it.



//Create all operator overloaded functions here. You need to figure out what you need by reading the client. 


//This is not an operator overloaded function.. This function will simplify a rational number to the simplest form.
//This is not an operator overloaded function.. This function will simplify a rational number to\
 
 //simplify 32/64 = 1/2( lowest common fact. is 2) 5/35 = 1/7 (lowest common factor is 5)         
 //while divisor != n(numerator)                                                                  
 // % = 0                                                                     
 rNum simplify(rNum& rational)
 {
   rNum temp; // this is to hold the rNum object we created when we call it
   //we call constructor so we dont change the original rNum
   int divisor = 1; //for counter, it should go up to 5 
   // we make temporary top and bottom so the top and bottom gets simplified seperately
   int n = rational.getTop(); //these are the temp top,  
   int q = rational.getBottom(); //temp bottom for the loop. 

   //do while loop while incrementing divisor, we want it to run still after condition is met
   do { // if top & bottom's remainer is 0// if divisor / top and bottom, it can simplify
     if (n % divisor == 0 && q % divisor == 0) {
       n = n / divisor; // divide the top by the divisor
       q = q / divisor; //divide the bottom by the divisor
     }
     divisor++; // increment divisor counter
   } while (divisor <= n); //whatever n and q is, we creat a new rNum object. put in temp variable which is temp
   temp = rNum(n, q);
   // return the simplified top and bottom
   return temp;
 }
