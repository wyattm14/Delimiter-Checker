//https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
//http://www.cplusplus.com/reference/stdexcept/out_of_range/

#include <fstream>
#include "GenStack.cpp"

// main function
int main(int argc, char **argv)
{
  fstream f;
  string path= "";
  char ch;
  char x;
  int count = 1;
  string answer = "y";
// while loop incase they want to repeat
  while (answer == "y" || answer == "Y"){
    //creating a new stack
    GenStack<char> *p = new GenStack<char>();

//getting user input
    cout << "\nPlease specify the file you would like to analyze" << endl;
    cout << "Be sure it is in the same directory" << endl;
    cin>> path;

    cout << "This is the path you entered: "<< path << endl;

//looping through the file path
    fstream fin(path, fstream::in);
    while (fin >> noskipws >> ch){
//getting the amount of lines so I can identify where the error is
      if (ch == '\n' ){
        count += 1;
      }
      // checking the opening brackets
      if (ch == '{'  || ch == '(' || ch == '['){
        p->push(ch);
        continue;
      }
      // checking the first closing bracket
      if (ch == ')'){
        //checing if the stack is empty
        if (p->isEmpty()){
          cout << "There is nothing to match ')' with, on line "<< count <<endl;
          //breaking the loop
          answer = "no";
        }
        //seeing if it matching
        x = p->peek();
        if (x == '{' || x == '['){
          cout<< "Wrong Type"<<endl;
          cout << "This is the wrong delimeter: "<< ch << endl;
          cout << "This error occured on line " << count << endl;
          break;
        }
        // if it is the same pop it
        if (x == '('){
          p->pop();
        }
      }
      // checking the first closing bracket
      if (ch == ']'){
        //checing if the stack is empty
        if (p->isEmpty()){
          cout << "There is nothing to match ']' with, on line "<< count <<endl;
          answer = "no";
        }
        //seeing if it matching
        x = p->peek();
        if (x == '{' || x == '('){
          cout<< "Wrong Type"<<endl;
          cout << "This is the wrong delimeter: "<< ch << endl;
          cout << "This error occured on line " << count << endl;
          break;
        }
        // if it is the same pop it
        if (x == '['){
          p->pop();
        }
      }
      // checking the first closing bracket
      if (ch == '}'){
        //checing if the stack is empty
        if (p->isEmpty()){
          cout << "There is nothing to match '}' with, on line "<< count <<endl;
          answer = "no";
        }
        //seeing if it matching
        x = p->peek();
        if (x == '(' || x == '('){
          cout<< "Wrong Type"<<endl;
          cout << "This is the wrong delimeter: "<< ch << endl;
          cout << "This error occured on line " << count << endl;
          break;
        }
        // if it is the same pop it
        if (x == '{'){
          p->pop();
        }
      }
    }
    // if the stack is empty then the program has succeeded, then check if they want to do another file
    if (p->isEmpty()){
      cout << "The delimeters are in good order" <<endl;
      cout << "Would you like to analyze another file? (Y/N)" <<endl;
      cin >> answer;

      if (answer == "Y" || answer == "y"){
        continue;
      }
      if (answer != "y" || answer != "Y"){
        break;
      }


    }
    //seeing which symbol never got matched
    else {
      cout << "This symbol never matched: "<< p->peek() <<endl;
    }
    // p->push('C');
    // cout << p->peek() << endl;



    return 0;
  }

  }
