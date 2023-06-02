#ifndef QUEUE_H
#define QUEUE_H
#include <string>

using namespace std;

const int QUEUE_SIZE = 10;
//create an enumuration type                                                                    
enum op {ADD, SUB, MULT, DIVI};
//create a struct that will have an operand, a operator, another operand        /*              
struct expr
{
  int oprd1;
  op oprt;
  int oprd2;
};
typedef expr el_t; // char for variables


class Queue
{

 private:

  el_t el[QUEUE_SIZE];
  int count;
  int front;
  int rear;
  void queueError(string msg);
 public:
  Queue();
  bool isEmpty();
  bool isFull();
  void add(el_t e);
  void displayAll();
  el_t remove();
  el_t getFront();
  void goToBack();
  int getSize();
};



#endif
