/****************************************************
Template written by Kazumi Slott
CS211
selection sort lab

This program has 4 different selection sort functions.
*****************************************************/
#include <iostream>
#include "array.h"
#include <cstdlib>
using namespace std;
//??????? include your array.h

int test(int code);

void selectionSort1(int array[], int N);
void selectionSort2(int array[], int N);
void selectionSort3(int array[], int N);
void selectionSort4(int array[], int N);

int main()
{
 
  srand(time(0));
  cout << "------ testing selectionSort1: Ascending moving largest to end  ------" << endl;
  test(1);//using switch statment to test sort 3   

  cout << "\n------ testing selectionSort2: Descending moving smallest to end  ------" << endl;
  test(2);//using switch statment to test sort 3   

  cout << "\n------ testing selectionSort3: Ascending moving smallest to beginning  ------" << endl;
  test(3);//using switch statment to test sort 

  cout << "\n------ testing selectionSort4: Descending moving largest to beginning  ------" << endl;
  test(4);//using switch statment to test sort 4   

  return 0;
}


//This function fills the array with random numbers between 1 and 100
void  fill(int array[], int s)
{
  for (int i =0; i < s; i++ ) {
    array[i] = (rand() % 100) + 1; //rand for random number through 100
  }

}

void print(int array[], int s){
  for (int i = 0; i < s; i++) {
    cout << array[i] << " ";
  }
  cout << "\n";
}

//int code = 1 for selectionSort1
//       2 for selectionSort2
//       3 for selectionSort3
//       4 for selectionSort4

int test(int code)
{
  const int SIZE = 10;
  //make a constant SIZE set to 10
  int arr[SIZE];
  //declare an integer array using SIZE  
  fill(arr, SIZE);
  //fill the array by calling fill()
  print(arr, SIZE);
  //print the array by calling print() in array.h
  // selectionSort2(arr, SIZE); 
  switch(code){
  case 1:
    selectionSort1(arr, SIZE);
    break;
  case 2:
    cout << "Case 2" << endl;
   selectionSort2(arr, SIZE);
   break;
   case 3:
    selectionSort3(arr, SIZE);
    break;
   case 4:
     selectionSort4(arr, SIZE);
    break;
  }
  //create a switch statement here to call a different sort function depending on the code.
  //here we will use the switch statement to chose how we sort the array(like smallest to highest, etc)
  print(arr, SIZE);
  //print the array - hopefully the numbers are sorted correctly

}



//this function sorts the numbers in ascending order by moving the largest to the end: smallest to largest
void selectionSort1(int array[], int N) 
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted part
  for(int last = N-1; last >= 1; last--) 
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted part ([0..last])
      for(int i = 1; i <= last; i++) 
	{
	  if(array[i] > array[lrgIndx]) //The current item is larger 
	    lrgIndx = i;
	}

      //swap the largest with the last item in the unsorted part
      temp = array[lrgIndx]; 
      array[lrgIndx] = array[last]; 
      array[last] = temp;
    } 
}



//Change this function so it sorts the numbers in descending order by moving the smallest to the end: largest to smallest                                                                    
//You can change the variable names to suit their purposes. 
//The structure of this code shouldn't change.
void selectionSort2(int array[], int N)
{
  int smallIndx; //index of smallest value                                                                                                                                               
  int temp; //the temp. value that holds the smallest value
  
  
  //last is the last index in unsorted area, sorts in descending(to the right).                                                                         
    for(int last = N-1; last >= 1; last--)
    {
  
      smallIndx = 0; //were assuming the last index is the smallest
                                                                                                                                      
      //we are sorting from the first index since we want the smallest in end. start from 2nd position(we declared first is 0)                            //ifcurrent item is smaller keep, then we keep it               
      for(int i = 1; i <= last; i++)
        {
          if(array[i] < array[smallIndx]) //if current index(left most) is smaller than right, smallest goes to current index were at.
	    
            smallIndx = i;
        }

      //swapping smallest with the last item in the unsorted array                                                                                                                           
      temp = array[smallIndx];
      array[smallIndx] = array[last];// swapping the smallest number to end
      array[last] = temp;
    }
}




//Change this function so it sorts the numbers in ascending order by moving the smallest to the beginning: smallest to largest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort3(int array[], int N)
{
  int smlIndx; //index of smallest value                                                                                                                                                                        
  int temp; //the temp value that holds the smallest value                                                                                                                                                                            
  //last is the last index in unsorted area                                                                                                                                                                                 
  for(int last = N-1; last >= 1; last--)//last( n) is the size, if size is greater than/equal to 1 we swap, last-- means we move to next index in array to compare 
    {
      smlIndx = 0; //assuming first index is the smallest then now going in the if loop below                                                                                                                                                                   
      //loop through array starting from 1st index and incrementing until we reach left side of array                                                                                                                                                                             
      for(int i = 0; i <= last; i++)
        {
          if(array[i] > array[smlIndx]) //if array[i] is smaller than array[smallest], there is an element in the right part that bigger.so smaller element gets moved to the beg while larger gets moved to the right side                                                                                                                                             
            smlIndx = i;
        }

      //temp is used to perform variable swap by storing value of the current small index into temp as a placeholder. it then swap array[last] with array[last]                                                                                                                                                                              
      temp = array[smlIndx];
      array[smlIndx] = array[last];
      array[last] = temp;
    }
}



//Change this function so it sorts the numbers in descending order by moving the largest to the beginning: largest to smallest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.

void selectionSort4(int array[], int N)
{
  int lrgIndx; //variable to hold index of largest numb in array                                                                                                                                                                      
  int temp; //temp value that hold large index(this is used once we come across an element in array thats larger than largindx)                                                                                                                                                       
  //loop starts at end of array and decrements until it reachs first index of array                                                                                                                                                                                 
  for(int beg = N-1; beg >= 1; beg--)
    {
      lrgIndx = 0; //assuming largest is                                                                                                                                                                   
      //loop through the array starting from the second position and decrement until we reach the left position of array                                                                                                                                                                             
      for(int i = 1; i <= beg; i++)
        {
          if(array[i] < array[lrgIndx]) //if array[i] is smaller than array[large] then we know therers an element on the right side of array that is bigger. bigger element gets moved to beginning by setting largeind to i                                                                                                                                            
            lrgIndx = i;
        }

      //temp is used to perform variable swap by storing value of current largindex into temp like a placeholder, then swap array[largeindex] with array[beg] to now move the largest array in the beg.
      temp = array[lrgIndx];
      array[lrgIndx] = array[beg];
      array[beg] = temp;
    }
}












