/*
Built in datatypes
 int
 float
 char
 double
 bool

User Defined Datatype
  Struct
  Union
  Enum

Derived Datatype
  Array
  Function
  Pointer
*/
#include<iostream>
using namespace std;

int global=10;
void fun(){
  cout<<"gloabal variable value"<<global;
}

int main(){
  int a=10, b=20; // same like in java
  float c=8.19;
  char d='r';
  int global=100;
  // int global=18; // if there is local variable with the same name of gloabal variable then it take the precedance on loacl variable
  cout<<"this will print local variable value "<<global<<"\n"; // this will print the value of global variable, you cant access this variable using this commond bcz its not in a class right now
  fun();

  bool _b = false; // false will get print as 0 and true will get print as 1
  return 0;
}