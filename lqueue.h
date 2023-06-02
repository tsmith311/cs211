#ifndef LQUEUE_H
#define LQUEUE_H
#include <string>
using namespace std;

typedef int el_t; // typedef el_t for the node   

struct node
{
  el_t elem; //element at this node is an integer
  node* next; // a pointer(link) to the next node

};


class LQueue
{
 private: 
  node* front; // front pointer
  node* rear; // rear pointer
  int count; // count is to keep track of the number of elements/nodes
  void queueError(string msg);
  void printAllReverse(node* p);
 public:
  LQueue(); // constructor
  ~LQueue(); // destructor
  void addRear(el_t el);
  bool isEmpty() const;
  void displayAll(); 
  el_t deleteFront();
  void printAllReverse();
};





#endif
