#include<iostream>
#include<string>
using namespace std;

class Y;

class X{
  int data;
  public:
    void setValue(int data){
      this->data = data;
    }

  friend int add(X, Y);
}x;

class Y{
  int num;
  public:
    void setValue(int data){
      this->num = data;
    }

  friend int add(X, Y);
}y;

int add(X a, Y b){
  return a.data+b.num;
}

int main(){
  x.setValue(1);
  y.setValue(1000);
  cout<<add(x, y)<<endl;
  return 0;
}