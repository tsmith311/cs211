#ifndef DLL_H
#define DLL_H
#include <string>
using namespace std;

typedef int el_t; // typedef el_t for the node   
struct node
{
  el_t elem; //element at this node is an integer
  node* next; // a pointer(link) to the next node
  node* prev; //pointer to prev node
};

class DLL
{
 private: 
  node* front; // front pointer
  node* rear; // rear pointer
  int count; // count is to keep track of the number of elements/nodes
  void queueError(string msg);
 public:
 DLL(); // constructor
  ~DLL(); // destructor
  void addRear(el_t el);
  bool isEmpty() const;
  void displayAll(); 
  el_t deleteFront();
  void addFront(el_t el); 
  el_t deleteRear();
  DLL(const DLL& source );
  void deleteNode(el_t e);
  bool search(el_t e);
  void addInOrderAscend(el_t e);
  void addInOrderDescend(el_t e);
  void printAllReverseDLL();
};





#endif
