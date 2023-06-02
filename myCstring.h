#include <string>

using namespace std;

//returns 1 or -1 if theyre diff
int myStrcmp(const char* cstr1, const char* cstr2)
{
  for(int i = 0; cstr1[i] != '\0' || cstr2[i] != '\0'; i++) 
    {                
      if(cstr1[i] != cstr2[i])          
	{
	  return cstr1[i] - cstr2[i]; 
	}
    } 
  return 0;

}
int myStrlen(const char* cstr)
{
  int i;
  for(i = 0; cstr[i]!= '\0';i++);
  
  return i;
}
void myStrcat(char* dest, const char* source)
{
  int d;
  int i;
  //Move d to the end of dest ('\0')                                            
  for(d = 0; dest[d] != '\0'; d++);
  //copy each character from source to dest                                     
  for(i = 0; source[i] != '\0'; i++)
    {
      dest[d++] = source[i];
    }

  //place '\0' at the end of dest                                               
  dest[d] = '\0';
}
void myStrcpy(char* dest, const char* source)
{
  int i;
  for(i = 0; source[i] != '\0'; i++)
    {
      dest[i] = source[i];
    }
  //Hint: I have only 4 lines of code inside this function                      
  dest[i] ='\0';
  //Don’t forget to place ‘\0’ at the end.                                      
}
//used to check to see if one of the words is bad
int binarySearch(const char** sortedAr, int size, const char* key)
{
  //  cout << "hi" << endl;
  int l = 0;
  int r = size - 1;
  int m;
  
  int temp;
  while(l <= r )
    {
      //            cout << "test 3" << endl;
      m = ((l + r)/2);
      //    cout << m;
      temp = myStrcmp(sortedAr[m], key);
       //   cout << "before if " << endl;
      if(temp == 0 )
	{
	  return m; // returning the index 
	}
      else if(temp > 0) // if temp is bigger than 0
	{
	  r = m - 1; 
	}else if(temp < 0)//if temp is less than 0,
	{
	  l = m + 1;
	}

    }// end of while loop
  //  cout << "After while" << endl;
  return -1;
}
