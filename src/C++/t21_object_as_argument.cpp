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

    void add(Complex c1, Complex c2){
      this->a = c1.a + c2.a;
      this->b = c1.b + c2.b;
    }

    void printComplex(){
      cout<<this->a<<"+i"<<this->b<<endl;
    }
}c;

int main(){
  Complex a, b;
  a.setValue(1,2);
  b.setValue(3,4);
  c.add(a, b);
  c.printComplex();
  return 0;
}