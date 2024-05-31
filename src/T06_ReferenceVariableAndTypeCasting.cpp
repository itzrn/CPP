#include<iostream>
#include<iomanip> // this is used to manupulate the output on the  console
using namespace std;

// :: -> this is called scope resolution operator, used to access the global variable if you have the same local variable too
int g=90;
int main(){
  // built in data type
  int g=100;
  cout<<"Local Variable -> "<<g<<endl;
  cout<<"Global Variable -> "<<::g<<endl; // this is the way to bring any gloabal variable value in the program function




  // Literals
  float d = 34.3f; // f make the compiler to know that the number is float
  long double e = 34.3l; // l make it long double
  cout<<"The value of d is -> "<<d<<endl<<"The value of e is -> "<<e<<endl;





  // Refernece valriable
  int x = 455; // here x-> is the original variable
  int &y = x; // y is the variable taking the reference of x
  cout<<x<<endl;




  // Type Casting
  int a=65;
  float b=134.3f;

  cout<<"Integer to Float -> "<<float(a)<<endl;
  cout<<"Float to Integer -> "<<int(b)<<endl;

  // constant keyword
  const int c=78; // this makes the value of variable constant, if you try to change it compiler give error


  // manupulation using setw, which is present in iomanip
  cout<<"The value of a is -> "<<setw(5)<<a<<endl;
  cout<<"The value of a is -> "<<setw(5)<<b<<endl;
  cout<<"The value of a is -> "<<setw(5)<<c<<endl;
  return 0;
}
