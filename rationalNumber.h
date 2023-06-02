
//define the rNum class here. The data members are top and bottom.
#ifndef rational_h
#define rational_h
//define the rNum class here. The data members are top and bottom.
class rNum
{
 private:
  int top;
  int bottom;

 public:
  rNum();
  rNum(int t, int b);
  void operator+=(const rNum&);
  bool operator==(const rNum&);
  friend ostream& operator<<(ostream& out,  rNum& p);
  friend istream& operator>>(istream& in, rNum& p);
  friend rNum operator+(const rNum&, const rNum&); 
  bool operator > (const rNum& rhs);
  // friend rNum operator+(const rNum&, const rNum& );
  friend rNum simplify(rNum&);
  //int rNum::simplify( const rNum& rational)
  int getTop();
  int getBottom();
  void setTop(int);
  void setBottom(int);
};


#endif 
