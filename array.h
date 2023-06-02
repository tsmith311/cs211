/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name: Tiera Smith
*****************************************************/
#ifndef ARRAY_H
#define ARRAY_H
#include <iomanip>
#include <iostream>
using namespace std;

template <class T>
void fill(T ar[], int n)
{
  for (int i = 0; i < n; i++ ) {
    // cout << "Enter your number:  ";
    cin >> ar[i];
     }
}
/********************************************
This function fills the array with data entered from the keyboard.
ar is an array of any data type
n is the number of items entered into ar
********************************************/
//       fill

/*
template <class T, class O>
void print(O &out, const T ar[], int n)
{
  for (int i = 0; i < n; i++) {
    cout << left;
    //    out << setw(10) << ar[i] << setw(10);
    }
  //cout << "\n"; // this is to print in a singular line left to right
}
*/


template <class T>
  void print( T ar[], int n)
{
  for (int i = 0; i < n; i++) {
    cout << left;
    cout << ar[i] << " ";
  }
    cout << "\n"; // this is to print in a singular line left to right
}


/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
       //         print


template <class T>
int getHighest(T ar[], int n){
  int pos = 0; //documenting what pos is highest currently, initially is first position
  //why do we assume? its all we know
  T highest = ar[0]; //assume the first index you come across in array is ur highest array
  //n = size
  // loop thru array
  for(int i = 1; i < n; i++) {
    if (highest < ar[i]) { //if highest is smaller than the next element in array, 
      highest = ar[i]; //highest will now be the next element in array
      pos = i; //document what position the next element was
       }
         cout << fixed << setprecision(2);
         cout << "highest is" << highest << endl;
    return highest;
  }
}
/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
       //       getHighest




/*******************************************
This function returns the index of the lowest value.
9
ar is an array of any data type.
n is the number of items in array
*******************************************/
       //       getLowest
template <class T>
T getLowest(T ar[], int n) {
   int i;
   T lowest = ar[0]; //assuming first index in array is lowest
    int pos = 0; //assuming first array is lowest, pos is 0
   //starting from beg of array, loop til end
   for(int i = 0; i < n; i++){
     // if lowest is larger than the next index we come across
     if (lowest > ar[i]) {
       lowest = ar[i]; //we make the lowest now equal to next index
     int  pos = i; // we save position of that index in pos
     }//end of if
   }

    cout << "The lowest score is " << lowest << " at " << pos << endl;
     return lowest;
}



/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
       //       getAvg
template <class T>
T getAvg(T ar[],int n)
{
  int total = 0;
  for (int i = 0; i < n; i++)
    {
      total += ar[i];
  }
   cout << "The average is " << (T)total / n << "\n";
  return (double)total / n;

}


/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4  
       
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar
*******************************************/
//*?????????/*
/*
template <class T>
int unique(const T ar[], T uniqAr[] , int n)
{
  int m = 0; //set index to 0 for loop
  //max is max amount of numb
  for(int i = 0; i < n; i++){
    bool found = false; //
   for (int max = 0; max <= m;max++){
    if (ar[i] == uniqAr[max]){                                                  
      found = true;
     }                    
   }
    if (found == false){
     uniqAr[m]= ar[i];
     
     }
  }
  return m;
}*/
//uniqAr in the caller will be filled with only unique numbers









/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class T>
T sort(T ar[], int N)
{
  int lrgIndx; //the index of the largest value                                                                                               
  T temp; //temporary variable that holds the largest value                                                                                  

  //last is the last index in unsorted portion                                                                                                 
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest                                                                                      
      //find the largest in unsorted portion ([0..last])                                                                                       
      for(int i = 1; i <= last; i++)
        {
          if(ar[i] > ar[lrgIndx]) //The current item is larger                                                                           
            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion                                                                            
      temp = ar[lrgIndx];
      ar[lrgIndx] = ar[last];
      ar[last] = temp;
    }
}

template<class T> //sorting in descending largest in beg
void bubbleSort(T ar[], int N)
{
  bool finished = false;
  int temp;
  while(!finished)
    {
      finished = true;
      for(int i = 0; i < N-1; i++)
        {
	  if(ar[i] > ar[i + 1])
            {
	      temp = ar[i];
	      ar[i] = ar[i + 1];
	      ar[i+1] = temp;
	      finished = false;
            }
        }
    }
}



template <class T1, class T2>
int find(const T1 classes[], int sz, const T2& key)
{
  //  T key;
  //if classes
  T1  potentialMatch;
  for(int i = 0; i < sz; i++)
    {
      potentialMatch = classes[i];
      if (potentialMatch == key) {
	return i;
    
      }
    
    }
  //if no matching, -1
  return -1;
}

//removes matching element(crn).returns true if it can remore. false if not. no error message in remove,call find
template <class T1, class T2>
bool remove(T1 ar[], int n, const T2&  el){
  
  int indexToBeDeleted = find(ar, n, el);

  if (indexToBeDeleted != -1){ // if its not -1, means deletion is able to occur
    n = n - 1;// size of array is reduced if deletion occurs

    for (int j = indexToBeDeleted; j <= n - 1;j++){
      ar[j] = ar[j + 1]; // set j to the next index, to shift array
    }
    return true; //we could find ar value, so we delete
  }
  return false; //cant find ar value to remove

}

#endif
