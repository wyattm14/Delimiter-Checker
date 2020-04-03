
// //https://www.techiedelight.com/stack-implementation-using-templates/

#ifndef GENSTACK_H
#define GENSTACK_H
#include <stdexcept>

#include "GenStack.h"

//default constructor
template <class T>
GenStack<T>::GenStack()
{
  myArray = new T [128];
  mSize = 128;
  top = -1;
}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize)
{
  myArray = new T [maxSize];//on the heap now
  //when you are inserting you have to check the bounds (if it is empty for example when removing)
  mSize = maxSize;
  top = -1;

}

template <class T>
GenStack<T>::~GenStack()
{
  delete myArray;
}

//push functions
template <class T>
void GenStack<T>::push (T data){
  //check if full before inserting
  if (isFull())
  {
    cout << "Full! " << endl;
    exit (EXIT_FAILURE);
  }
  cout << "Inserting: " << data << endl;

  myArray[++top] = data;//incremented top and inserted the value
}


template <class T>
T GenStack<T>::pop(){
//seeing if the stack has things in it
  if (top >= 0){
    cout << "Removing: " << peek()<< endl;
    return myArray[top--];
//if it is empty
  }else {
    throw out_of_range ("\nPOP EXCEPTION THROWN. THE STACK IS EMPTY");
    // return '\0';
  }

  // if (isEmpty())
  // {
  //   cout << "Empty! " << endl;
  //   exit (EXIT_FAILURE);
  // }
  //
  // cout << "Removing: " << peek()<< endl;
  //
  // return myArray[top--];

}
//peek function
template <class T>
T GenStack<T>::peek(){
  //check if empty before proceeding to remove
  if (!isEmpty()){
    return myArray[top];
  }
  else{
    exit(EXIT_FAILURE);
  }

}
// checking if it is full
template <class T>
bool GenStack<T>::isFull(){
  return (top == mSize-1);
}
//checking if it is empty
template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}



#endif
