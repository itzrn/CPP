#include<iostream>
#include<string>
using namespace std;

class Complex{
  int a, b;
  public:
    void setValue(int a, int b){
      this->a=a;
      this->b=b;
    }

    // friend function won't get the part of this class, friend function only get some access of this class

    friend Complex sumComplex(Complex, Complex);
    // or friend Complex sumComplex(Complex o1, Complex o2);
    void print(){
      cout<<this->a<<" + "<<this->b<<"i"<<endl;
    }
}a, b;

Complex sumComplex(Complex c1, Complex c2){
  Complex c3;
  c3.setValue(c1.a+c2.a, c1.b+c2.b);
  return c3;
}

int main(){
  a.setValue(4, 8);
  a.print();
  b.setValue(1, 4);
  b.print();

  Complex c=sumComplex(a, b);
  c.print();
  
  return 0;
}

/*
Properties
1. Not in the scope of class
2. since it is not in the scope of class, it can not called by the object of the class
3. can be invoke with out any object
4. usually contains objects as argument
5. can be declare inside private or public section of the class
6. it can not access the member by there names and need object _name.member_name to access any member
*/