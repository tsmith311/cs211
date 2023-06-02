#ifndef postfix_h
#define postfix_h

class Postfix
{
 public:
  bool isOperand(char);
  int charToInt(char);
  bool isOperator(char);
  int doMath(int, char, int);
};

#endif /* postfix_h */
