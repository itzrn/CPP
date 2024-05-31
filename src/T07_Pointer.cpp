#include<iostream>
using namespace std;

int main(){
  /*
  & -> Address of operator
  * -> Dereference operator
  */

  int a=3;
  int* b=&a; // b is just a pointer which stores the address of a(not the value kept at a)
  // &a -> means address of a
  // * denote that the variable b contains the address of any other variable

  cout<<b<<endl;
  cout<<"Address of a -> "<<&a<<endl;
  cout<<"Address of b which Dereference a -> "<<b<<endl;
  
  cout<<"To know the value at b -> "<<*b<<endl; // using derefence operator to know the current value at pointer
  // *b -> value of b

  //pointer of pointer
  int** c=&b; // to know the value -> *c
  return 0;
}