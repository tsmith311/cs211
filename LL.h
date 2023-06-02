#ifndef LL_H
#define LL_H
#include <string>
using namespace std;

typedef int el_t; // typedef el_t for the node   
struct node
{
  el_t elem; //element at this node is an integer
  node* next; // a pointer(link) to the next node

};

class LL
{
 private: 
  node* front; // front pointer
  node* rear; // rear pointer
  int count; // count is to keep track of the number of elements/nodes
  void queueError(string msg);
 public:
  LL(); // constructor
  ~LL(); // destructor
  void addRear(el_t el);
  bool isEmpty() const;
  void displayAll(); 
  el_t deleteFront();
  void addFront(el_t el); 
  el_t deleteRear();
  LL(const LL& source );
  void deleteNode(el_t e);
  bool search(el_t e);
  void addInOrderAscend(el_t e);
  void addInOrderDescend(el_t e);
};





#endif
