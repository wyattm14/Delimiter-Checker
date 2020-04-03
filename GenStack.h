#include <iostream>
#include <cstdlib>

using namespace std;
template <class T>
class GenStack
{
public:
  GenStack(); // default constructor
  GenStack(int maxSize); //overloaded
  ~GenStack();//destructor
  //functions
  void push(T data); //insert
  T pop(); //remove

  //helper functions
  bool isFull();
  bool isEmpty();
  T peek();
  int mSize; //max size of the stack
  int top;// variable to keep track of indicies representing the top of our stack

  T *myArray; //declaring a pointer, comes in at runtime
};
