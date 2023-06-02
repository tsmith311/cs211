/********************************************
Template created by Kazumi Slott
CS211
Date: ????????????????
Your name: ???????????????
Description of your program: ???????????????
********************************************/
#include <iostream>
using namespace std;
#include "array.h"  //This is your array.h
#include "rationalNumber.h"

int main()
{
  const int SIZE = 3;
  
  rNum n1;
  rNum n2;
  rNum ans;

  cout << "\n-------------- 1 -----------------" << endl;
  cout << "Rational Number 1";
  cin >> n1;
    
  cout << "n1 is " << n1 << endl;
 
  cout << "\n-------------- 2 -----------------" << endl;
  cout << "\nRational Number 2";
  cin >> n2;
  
  cout << "n2 is " << n2 << endl; 
 
  cout << "\n-------------- 3 -----------------" << endl;
  n1 = simplify(n1);
  ans = n1 + n2;
 
  cout << n1 << " + " << n2 << " = " << ans << endl;

  cout << "\n-------------- 4 -----------------" << endl;
  //Declare an array of rNums that has SIZE slots
  rNum rNumArray[SIZE];
 
  //fill the array by calling fill() in your array.h
  fill(rNumArray, SIZE);


  cout << "Checking to see if the array is filled" << endl;
  //print the array by calling print() in your array.h
  print(rNumArray,SIZE);

  cout << "\n-------------- 5 -----------------" << endl;
  //sort the array in ascending order by calling sort() in your array.h
  sort(rNumArray, SIZE);

  cout << "Checking to see if the array is sorted in ascending order" << endl;
  //print the array by calling print() in your array.h
  print(rNumArray,SIZE);

  cout << "\n-------------- 6 -----------------" << endl;
  cout << "Checking to see if " << n1 << " is in the array " << endl;
  //Call find() in your array.h to see if n1 exists in the array. Say found or not found. See #6 in the test runs in the hw document.   
  if (find(rNumArray, SIZE, n1)) {
    cout << "found" << endl;
  }
  else {
    cout << "not found" << endl;
  }
 
  cout << "\n-------------- 7 -----------------" << endl;
  cout << "n1 is " << n1 << " n2 is " << n2 << " before n1 += n2" << endl;
  n1 += n2;
 
  cout << "After n1 += n2, n1 is " << n1 << endl << endl;
    
  return 0;
}



