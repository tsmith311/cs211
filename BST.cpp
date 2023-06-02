//#include "LL.h"
#include <iostream>
#include <cstdlib> //for rand()
#include <fstream>

using namespace std;

typedef int el_t;

class Node
{
  friend class BST;
private:
  el_t elem;
  Node* right;
  Node* left;
public:
  Node(el_t e){elem = e; right = NULL; left = NULL;}; //implement the constructor inside the class definition
  

};

class BST
{
private:
  Node* root;
  void insertNode(Node*&, el_t);
  void destroy(Node* p);
  void inOrderPrint(Node* p);
  void postOrderPrint(Node* p);
  void preOrderPrint(Node* p);
  int getMaxLength(Node* p);
  bool searchRec(Node* p, el_t e);
  int getNumNodesBetween(Node* p, int minNum, int maxNum);
  void printNodeBetween(Node* p, int minNum, int maxNum);
public:
  BST();
  ~BST();
  void insertNode(el_t);
  bool search(el_t e);
  void inOrderPrint();
  void postOrderPrint();
  void preOrderPrint();
  int getMaxLength();
  bool searchRec(el_t e);
  int getNumNodesBetween(int minN, int maxN);
  void printNodeBetween(int minN, int maxN);

};

BST::BST()
{
  root = NULL;
}

void BST::insertNode(el_t e)
{
  insertNode(root, e);
}

void BST::insertNode(Node*& p, el_t e)
{
  if(p == NULL)
    p = new Node(e);
  else if(e < p->elem)
    insertNode(p->left, e);
  else
    insertNode(p->right, e);
}
 
bool BST::search(el_t e)
{
 
  Node* p = root;
  int count = 0; // counter
  while(p != NULL) 
    {
      count ++;
      if (p->elem == e)
	{
	  cout << count << endl;
	  cout  << " nodes checked" << endl;
	  cout << "found" << endl;
	  return true;
	  
	}else if(e < p->elem)
	{
	  p = p->left;

	}else if (p->elem < e)
	{
	  p = p->right;
	}
    }

  cout << count << " nodes checked" << endl;
  cout << " NOT found " << endl;
  return false; //if not found
}



BST::~BST()
{
  destroy(root);
}

void BST::destroy(Node* p)
{
  if(p == NULL)
    return;
  destroy(p->left);
  destroy(p->right);
  //  cout << p->elem << "-->";
  delete p;
}


void BST::inOrderPrint()
{
  inOrderPrint(root);
}

//prints in order 
void BST::inOrderPrint(Node* p)
{
  if(p == NULL)
      return;
  inOrderPrint(p->left); // goes thru left child
  cout << p->elem << "-->"; //then prints the elem of node
  inOrderPrint(p->right); //goes through the right child
    
}

void BST::preOrderPrint()
{
  preOrderPrint(root);
}

//par->left->right
void BST::preOrderPrint(Node* p)
{
  if(p == NULL)
      return;
  cout << p->elem << "-->"; //parent is printed first
  preOrderPrint(p->left); //gpes to left 
  preOrderPrint(p->right); //then goes to right
    
  
}

void BST::postOrderPrint()
{
  postOrderPrint(root);
}
//parent is last ! left->right->parent
void BST::postOrderPrint(Node* p)
{
  if( p == NULL)
    return;
  postOrderPrint(p->left);// goes to left subtree firsy
  postOrderPrint(p->right); //then to the right subtree
  cout << p->elem << "-->"; // then prints the elem
}

int BST::getMaxLength()
{
  return getMaxLength(root);
}

int BST::getMaxLength(Node* p)
{
  if(p == NULL)
    {
      return 0;
    }  
  if(getMaxLength(p->left) > getMaxLength(p->right))
    {
      return getMaxLength(p->left) + 1;
    }
  else
    {
      return getMaxLength(p->right) + 1;
    }
}

bool BST::searchRec(el_t e)
{
  return searchRec(root, e);
}

bool BST::searchRec(Node* p, el_t e)
{
  if(p == NULL) 
    {
      return false;
    }
  if(p->elem == e) //if root is e(what user is searchign for)
    {   
      return true; //true
    }
  else if(p->elem > e)  // if root is bigger than e, 
    {
      return searchRec(p->left, e); //search the lefr child
    }
  else if(p->elem < e) //if less than e
    {
      return searchRec(p->right, e); //search the right child
    }
}


int BST::getNumNodesBetween(int minN, int maxN) // public
{
  getNumNodesBetween(root, minN, maxN);
}

int BST::getNumNodesBetween(Node* p, int minNum, int maxNum) //private function
{
  if(p == NULL)// no mroe nodes
    return 0;
  if(p->elem == maxNum && p->elem == minNum)  //if root is max and min
    {
      return 1; // return 1 since you dont have to check the tree 
      }
  if(p->elem > minNum && p->elem < maxNum) // need to check if its in range first,
    {
      return getNumNodesBetween(p->left, minNum, maxNum) + getNumNodesBetween(p->right, minNum,\
									      maxNum) + 1; 
      //if in range itll count nodes in left and right child and root (+1)
    }
     if(p->elem < minNum) //if p->elem is smaller than min, go throught the right child
    {
      return getNumNodesBetween(p->right, minNum, maxNum); //
    }else if(p->elem > minNum) // if p->elem is bigger than min go through the left child
    {
      return getNumNodesBetween(p->left, minNum, maxNum);
    }
}
void BST:: printNodeBetween( int minN, int maxN) //public
{
  printNodeBetween(root, minN, maxN);
}

void BST::printNodeBetween(Node* p,int minNum, int maxNum) //private
{
  if(p == NULL)
    return;
  if(minNum < p->elem) //if root is bigger than minNum, go to left child and search 
    printNodeBetween(p->left, minNum, maxNum);
  if(minNum <= p->elem && maxNum >= p->elem) // if within the range print out nodes
    {
      cout << p->elem << "-->";
    }
  if(maxNum > p->elem) //if root is smaller than max num, go toright child and search
    {
      printNodeBetween(p->right, minNum , maxNum);
    }
}

int main()
{
  /*
  srand(time(0)); //you need to include cstdlib
  BST test;
  LL test2;
  int random;  
  for(int i = 0; i < 100000; i++) //add 100000 random numbers to bst and LL
    {
      random = rand()% 100001;
      test.insertNode(random);
      test2.addRear(random);
    } 

  int key;
  cout << "What number do you want to search for? ";
  cin >> key;
  
  cout << "BST *************************" << endl;
  
  test.search(key);
    
  cout << "LL************************" << endl;
  test2.search(key);
  
  */
  /*
  BST b;
  
  b.insertNode(5); 
  b.insertNode(8); 
  b.insertNode(3); 
  b.insertNode(9); 
  b.insertNode(6); 
  b.insertNode(1); 
 
  b.insertNode(0); 
  b.insertNode(4); 
  b.insertNode(7); 
  b.insertNode(20);
  
  BST t;
  t.insertNode(5);
  t.insertNode(3);
  t.insertNode(8);
  t.insertNode(6);

  cout << "---- Print all elements using the in-order traversal -----" << endl;  
  b.inOrderPrint();
  cout << endl;
  cout << "---- Print all elements using the pre-order traversal -----" << endl;  
  b.preOrderPrint();
  cout << endl;
  cout << "---- Print all elements using the post-order traversal -----" << endl;  
  b.postOrderPrint();
  cout << endl;
  //  cout << "\n--- destructor gets called when b goes out of scope here ---" << endl;
  
  cout << "Testing getMaxLengnth()" << endl;
  cout <<  b.getMaxLength();
  cout << endl;
  cout << t.getMaxLength();
  cout << endl;
  cout << "Testing search Rec" << endl;

  cout <<  b.searchRec(5);
  cout << endl;
*/

  BST b; // bst object 
  ifstream input; 
  input.open("bst.dat"); 
  int max;
  int min;
  int data;

  cout << "Enter min: " << endl;
  cin >> min;

  cout << "Enter max: " << endl;
  cin >> max;

  if(!input) //file doesnt exist
    {
      cout << "cant open file" << endl;
    }
  else
    { //file exists
      input >> data;
      while(input)
	{
	  b.insertNode(data);
	  input >> data;
	}
      cout << "The number of nodes between " << min << " and " << max << " is ";
      cout << b.getNumNodesBetween(min, max);
      cout << endl;
      cout << "---------------The number of nodes between " << min << " and " << max << " found in the tree are----------- ";
      cout << endl;
      b.printNodeBetween(min, max);

    }  
   
  input.close(); //closing file





  return 0;
}
