#ifndef ULTILITY_H
#define UTILITY_H
#include "LL.h" 
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

void buildLL(LL&);
bool isLetter(char);
char myToLower(char);
char toMyUpper(char);
string stripStr( const string&);
void removeBadWords(LL& );
void outputToFile(LL&);


string stripStr(const string& wd) 
{ 
  string w = ""; 

  for(int i = 0; i < wd.length(); i++) //go through each character in wd 
    { 
      if( isLetter(wd[i])) //if its a letter
	{
	  w += myToLower(wd[i]); //
	}
    } 
  
  return w;
} 

void buildLL(LL& str)
{
  string word;
  ifstream input("essay.txt"); //object declaration for file
  // while(!input.eof())    
    if(!input) //doesnt exist
      {
	cout << "Cant open file" << endl;
      }else{ // file exists
      while(!input.eof())
	{
	  input >> word;

	  if(str.search(stripStr(word))) // if theres duplicates 
	    {
	      str.deleteNode(word); //delete the duplicate
	    }
	  else
	    {
	      str.addInOrderAscend(stripStr(word)); // add words to LL

	    }
	}

      input.close();
      //            str.displayAll();
    }
}

void removeBadWords(LL& str)
{
  string word;
  ifstream input("bad.txt"); // opening txt file

  if(!input)//if file doesnt exist
    {
      cout << "cant open file." << endl;
    }else{
    while(!input.eof())
      {
	input >> word;
	//	cout << word << endl;
	if(str.search(word)) //use search function for the bad words
	  {
	    //  cout << "hello" << endl;
	    str.deleteNode(word); //delete the bad words from the txt file
	  }
      }
  }
  
  input.close(); //close the file
  str.displayAll(); //for testing
}

void outputToFile(LL& str)
{

  //  string fileName = "./dictionary/A.txt";
  string s; 
  char d, temp = 'A';
  string filename = "./dictionary/?.txt";
  ofstream fout("essay.txt");
  if(!fout)
    {
      cout << "File doesnt exist" << endl;
    }else{
    while(!str.isEmpty())
      {
	s = str.deleteFront(); //to get the letter for sorting 
	d = toMyUpper(s[0]); // d now has the letter, change a -> A
	//      	d = s[0];
	filename[13] = d; // make the file name with d
	if(d != temp)
	  {
	    fout.close(); // close the file
	  }
	temp = d;
	fout.open(filename.c_str());
	fout << s;
      }
    fout.close();
  }
  // fout.close();
  
}

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

char toMyUpper(char t)
{
  char upperCase = toupper(t);

  return upperCase;

}



#endif
