#include<iostream>
using namespace std;

/*
We do have struct in cpp then why we use class?
1. The reason is access modifiers
we can not protect our data using public private protected, but class can do.
2. we can not put function in struct

use struct when there is not much concern of data, only use to hold data.
*/

class Employee{
  private: // this can only be accessed by the function of its class, it can not be accessed by other classes or by the function outside of class untill and unless the created function is of particular class.
    int a, b, c;
  
  public:// this can be accessed anywhere
    int d, e;
    void setData(int a1, int b1, int c1); // its your choice to implement the function later
    void getData(){ // or to implement the function later
      cout<<"The value of a -> "<<a<<endl; 
      cout<<"The value of b -> "<<b<<endl;
      cout<<"The value of c -> "<<c<<endl;
      cout<<"The value of d -> "<<d<<endl;
      cout<<"The value of e -> "<<e<<endl;
    }
};

void Employee :: setData(int a1, int b1, int c1){ // this is need to be written after the class constructed
  a=a1;
  b=b1;
  c=c1;
}


int main(){
  Employee aryan; // declaration
  aryan.setData(1,2,3);
  // aryan.a = 10; -> this wil through error, bcz a is private
  aryan.d=34;
  aryan.e=89;
  aryan.getData();
  return 0;
}