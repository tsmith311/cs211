#include "LL_T.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void createLL(LL<string>&, string&);
bool isLetter(char);
char myToLower(char);
bool palindrome(LL<string>& str, string& s );

void createLL(LL<string>& str, string& s)
{
  string element;
  int i;
  int length = s.size(); //to get the size of s(string)
  
  for(int i = length; i >= 0; i--) //making the string reverse
    {
      if(isLetter(s[i])) // here we call isLetter
        {
	  element = myToLower(s[i]); //to change upper to lower           
	  //	  cout <<element<< endl;
	  str.addFront(element); //adding element to front, if it was rear it would be backwards
        }
      	
	}  

}
//copy the isalpha function
bool isLetter(char s)
{

  if(isalpha(s)) // call isalpha with s
    {
      return true;
    }
  return false;

}


char myToLower(char t)
{
  char lowerCase = tolower(t); //create variable then call tolower
  
  return lowerCase; //return variable
}

bool palindrome(LL<string>& str, string& s )
{
  
   string front, rear; 
  // LL linkList;
  createLL(str, s);
 
  // for(int i = 0; i < s.size(); i++)
  while(!str.isEmpty()) //while its not empty
    {
      front = str.deleteFront(); //front is delete front
      rear = str.deleteRear(); //rear is delete rear
      if(front != rear) // if front doesnt equal rear
	{
	  cout << endl;
	  // str.displayAll();
		  //	  cout  << " is not a palindrome" << endl;
	  return false; // not a palindrome
	}

    }
  cout << endl;
  //  str.displayAll();
  // cout  << "is Palindrome." << endl; // its a palindrome so true
  return true;

}

int main()
{

  LL<string> test;
  string s;
  /*
   cout << "Enter a sentence: " << endl;
  getline(cin, s);


  createLL(test, s); 

  if(palindrome(test,s))
    {
      cout << "\"" << s << "\"" << "is a palindrome";  
    }
  else {
    cout << "\"" << s << "\"" << "is NOT a palindrome";  
  }

  */
  
  ofstream fout;
 

  
  ifstream fin("palindrome2.dat");
  while(!fin.eof())
  if(!fin)
    {
      cout << "Cant open file" << endl;
    }else { //file exists

    string s;
    while(!fin.eof())
      {
	getline(fin,s);
	test.~LL();
	
     
	 createLL(test, s);
	 if(palindrome(test, s))
	   {
	     cout << "\"" << s << "\"" << "is a palindrome";
	  //          palindrome(test,s);
	  // test.displayAll();
	   }else {
	   cout << "\"" << s << "\"" << "is not a  palindrome";
	 }
      }
  }
  
  fin.close();
      fout.close();
    
  
  

  
  return 0;
}
