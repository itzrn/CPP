#include<iostream>
#include<string>
using namespace std;

class Complex; // this line tell the complier that the complex class is present if you keep on search forward.

class Calculator{
  public:
    int add(int a, int b){
      return a+b;
    }

    int sumRealComplex(Complex a, Complex b);
    int sumComComplex(Complex a, Complex b);
}cal;

class Complex{
  int a, b;

  // this is the individual decalaration of calculator function as friend
  // friend int Calculator::sumRealComplex(Complex, Complex);
  // friend int Calculator::sumComComplex(Complex, Complex);

  // alter : declating the entire calculator class as friend
  friend class Calculator;
  public:
    void setValue(int a, int b){
      this->a=a;
      this->b=b;
    }

    void print(){
      cout<<this->a<<" + "<<this->b<<"i"<<endl;
    }
}a, b;

int Calculator :: sumRealComplex(Complex a, Complex b){
  return a.a+b.a;
}
int Calculator :: sumComComplex(Complex a, Complex b){
  return a.b+b.b;
}



int main(){
  a.setValue(1, 4);
  b.setValue(5, 7);
  int res = cal.sumRealComplex(a, b);
  cout<<"The sum of the real part of a and b is -> "<<res<<endl;
  int resc = cal.sumComComplex(a, b);
  cout<<"The sum of the Complex part of a and b is -> "<<resc<<endl;
  return 0;
}