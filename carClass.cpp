#include <iostream>
using namespace std;

enum direc{NORTH, EAST, SOUTH, WEST};

//class definition
class Car
{
private: //data memebers, cant be accessed from out of class
  string model;
  int year;
  int X;
  int Y;
  direc direction;
   int mileage;
public://member functions can be accessed outside of memeber functions prototypes g here these are attattribute
  void turnRight();
  void turnLeft();
  int getYear() const;
  int getX() const;
  int getY() const;
  string  getDirection() const;
  void goForward(int blk);
  int getMileage() const;
  string getModel() const;
  Car(string md, int yr);
  //  void turnRight();
}; // class definition ends with ;

//constructir job is to set values to the attributes
Car::Car (string md, int yr)
{
  model = md;
  year = yr;
  X = 0;
  Y = 0;
  direction = NORTH;
  mileage = 0;

}

int Car::getYear() const
{
  return year;
}

int Car::getX() const
{

  return X;

}

int Car::getMileage() const
{

  return mileage;
}

int Car::getY() const
{

  return Y;

}

void Car::turnRight()
{

  if(direction == WEST)
    direction = NORTH;
  else
  direction = (direc) (direction + 1);
}


string Car::getDirection() const
{

  switch(direction)
    {
    case NORTH: return "North";
    case EAST: return "East";
    case SOUTH: return "South";
    case WEST: return "West";

    }
  // return direction;
}

string Car::getModel() const
{

   return model;
}

void Car::turnLeft()
{
  if (direction == NORTH)
    direction = WEST;
  else
    direction = (direc) (direction - 1);

}


// if car facing east change x, if change north change y
//add mileage
 void Car::goForward(int blk)
{
    
  if(direction == NORTH){
    Y +=blk;
  }
  else if(direction == EAST){
    X+=blk;
  }
  else if(direction == SOUTH){
    Y-=blk;
  }
  else{ //direction == west
    X-=blk;
  }

  mileage+= blk;
}

void const showInfo(Car c);

// outside car class
int main()
{

   
  Car cl("Camry", 2020); //car objects
  Car c2("Neon", 2022); 
     
  //testing comment out

  //cL faces north and begins at 0 0 
 
  /*
    cl.goForward(0);
    cout << cl.getX() << " " << cl.getY() << endl;
  */
 
    cl.goForward(3);
    cl.turnRight(); //facing east 0 3
    cout << cl.getDirection() << endl;
    cout << cl.getX() << " " << cl.getY() << endl;
   cl.goForward(5);
   cl.turnRight(); // 5, 3 south
   cout << cl.getDirection() << endl;
   cout << cl.getX() << " " << cl.getY() << endl;
   cl.goForward(7);
   cl.turnRight(); // 5 -4 west
   cout << cl.getDirection() << endl;
   cout << cl.getX() << " " << cl.getY() << endl;
   cl.goForward(6);
   cl.turnLeft();
   cout << cl.getDirection() << endl; // -1 -4 south
   cout << cl.getX() << " " << cl.getY() << endl;
   cl.goForward(1); // -1 -5 
   cout << cl.getDirection() << endl;
   cout << cl.getX() << " " << cl.getY() << endl;
   cout << "Mileage is:" << cl.getMileage() << "\n";

   showInfo(cl);
   
   
   //c2
   c2.goForward(5);
   c2.turnLeft();
   cout << c2.getDirection() << endl;
   cout << c2.getX() << " " << c2.getY() << endl; //f 5 l
   c2.goForward(1); 
   c2.turnLeft();
   cout << c2.getDirection() << endl;
   cout << c2.getX() << " " << c2.getY() << endl;
   c2.goForward(2);
   c2.turnLeft();
   cout << c2.getDirection() << endl;
   cout << c2.getX() << " " << c2.getY() << endl;
   c2.goForward(6);
   c2.turnLeft();
   cout << c2.getDirection() << endl;
   cout << c2.getX() << " " << c2.getY() << endl;
   c2.goForward(4);
   c2.turnLeft();   
   cout << c2.getDirection() << endl;
   cout << c2.getX() << " " << c2.getY() << endl;
   c2.goForward(10);
   cout << c2.getDirection() << endl;
   cout << c2.getX() << " " << c2.getY() << endl;

   showInfo(c2);


   return 0;
}


//Car is called from class using the public objects, parameter is name of class and a variable to hold objects. //basically like struct
void const showInfo(Car c)
{
  //
  cout << c.getModel() << " " <<  c.getYear() << "is located at " << "(" << c.getX() << "," << c.getY() << ")" << "faceing " << c.getDirection() << "." << "it has " << c.getMileage() << " miles on it" << endl;

}

//we call the make, location, and mileage




