#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class myVector
{
private:
  T* ar; //pointer to an array, stores address of our vector
  int num; //the number of elements in the array pointed to by ar
public: 
  myVector();
  ~myVector();
  void push_back(const T& e);
  int size() const;
  T& operator[](int index) const;
  void erase(int index);
  void insert(int index, const T& e); // the new element e will sit at the index
};


template <class T>  // need this above each function in this lab
myVector<T>::myVector()// use T even if you are not using T inthsi function
{
  //initialize ar and num
  // initialize ar to NULL
  // init num to ?? 
  ar = NULL;
  num = 0; // keeps track of size of vector
}

template <class T>
myVector<T>::~myVector() //destuctor
{
  if(ar != NULL)
    {
      delete [] ar; // if ar points to an array, delete it
    }
}

//push elements into the vector from the back, size is increased by 1
template <class T>
void myVector<T>::push_back(const T& e) //e could be big, use pass by reference
{
  //1. make dynamic array with 1 more slot 

  T* tempArr = new T[num + 1]; // creating new dynamic array
  
  //make a copy of the old elements in array in the new array using *
  for (int i = 0; i < num;i++)
    {
      //moving down the array
      *(tempArr + i) = *(ar + i); //array(tempARR) is the new array, ar is the original (right)
    }
  //e has the value of the copied array(tempar)
  *(tempArr + num) = e;
  if (ar != NULL) {

  
  delete []ar; // we delete to prevent any memory leakas
  }
  ar = tempArr;
  
    //increasing size of array and add element to end of array
  num++;

}

template <class T>
int  myVector<T>::size()const
{
  return num; // for get size
}

template <class T>
T& myVector<T>::operator[](int index) const
{
  //if index is less than the number of numbers in the arrat
  if (index < num) {
    //pointer arr is added
    return *(ar + index);
  }
  else {
    // else we cout invalid
    cout << "invalid" << endl;
  }
}
//takes out functins inside th array
template <class T>
void myVector<T>::erase(int index)
{
  //if index is larger than size of array, diisplay illegal index
  if(index > (num - 1))
    {
      cout << "illegal index" << endl;
    }
  else {
    T* newArr = new T[num]; //making a new array 1 les than the size of the array (to delete) making new dynamic array 
    for (int i = 0; i < index; i++) // when index is i 
      {
	*(newArr + i) = *(ar + i); //pointing newArr + 1 to ar+1
      }
    for (int i = index; i < (num + 1); i++)
      {
	*(newArr + i) = *(ar + (i + 1));
      }
    if (ar != NULL) {
      delete []ar; // delete ar 
      ar = newArr; // point ar to new arr
      num--; // decrement num
    }
  }
  
}
//you can insert an element at a position you pick
template<class T>
void myVector<T>::insert(int index, const T& e) {
  if (index < 0 || index > num)
    {
      cout << "illegal index" << endl;
    }
  else
    {
      T* tempArray = new T[num + 1]; // making 
      for (int i = 0; i < num; i++)
        {
	  *(tempArray + i) = *(ar + i);
        }
      num++;
      T temp1 = *(tempArray + index);
      for (int i = index; i < num; i++)
        {
	  T temp2 = *(tempArray + (i + 1));
	  *(tempArray + (i + 1)) = temp1;
	  temp1 = temp2;
        }
      //e now has the 
      *(tempArray + index) = e;
      if (ar != NULL)
        {
	  delete[]ar;
	  ar = tempArray;
        }
    }
}

#endif
/*
template <class T>
void print(const myVector <T>& v)
{
  for (int i = 0; i < v.size(); i++)
    {
      cout << "[" << v[i] << "]"; //prints all the elements in the vector                          
   }
  cout << endl;
}


int main()
{
  myVector<int> v; 
  //test the vector functions
  //call push_back() multiple times
  v.push_back(1);
  v.push_back(2);
  v.push_back(9);
  v.push_back(3);
  //  v.print(v);
  v.erase(2);

  //call print to show all elements in the vector after deleting the element at index 2
  cout << "testing push_back - print all elements (1 2 3) in vector" << endl;
  print(v);

  cout << "testing illegal erase(should print illegal index)" << endl;
  v.erase(3);
  print(v);
  
  myVector<int> insertTest;
  insertTest.push_back(1);
  insertTest.push_back(2);
  insertTest.push_back(3);

  insertTest.insert(1, 9);
  cout << "testing insert at index 1, vector should be 1 9 2 3" << endl;
  print(insertTest);

  insertTest.insert(4, 5);
  cout << "testing insert at index 4, vector should be 1 9 2 3 5" << endl;
  print(insertTest);

  insertTest.insert(6, 7);
  cout << "testing illegal index insertion at index 6. Should print illegal index" << endl;
  print(insertTest);
  
  return 0;
}



/*
template <class T>
void print(const myVector <T>& v)
{
  for (int i = 0; i < v.size(); i++)
    {
      cout << "[" << v.ar[i] << "]"; //prints all the elements in the vector     \
                                                                                  
    }
  cout << endl;
}
*/
