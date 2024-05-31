#include<iostream>
using namespace std;


// try to use inline function for small functions, this save the resources
inline int product(int a, int b){ // do not use inline in recursiove or complex fucntion or if the function conatins any static variable
  return a*b;
}

int main(){
  int a, b;
  cout<<"Enter the value of a and b"<<endl;
  cin>>a>>b;

  cout<<"Product -> "<<product(a, b)<<endl;
  cout<<"Product -> "<<product(a, b)<<endl;
  cout<<"Product -> "<<product(a, b)<<endl;
  cout<<"Product -> "<<product(a, b)<<endl;
  cout<<"Product -> "<<product(a, b)<<endl;
  cout<<"Product -> "<<product(a, b)<<endl;
  cout<<"Product -> "<<product(a, b)<<endl;
  cout<<"Product -> "<<product(a, b)<<endl;
  cout<<"Product -> "<<product(a, b)<<endl;
  return 0;
}