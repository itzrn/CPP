#include<iostream>
#include<string>
using namespace std;
class C2;
class C1{
  int data1;
  public:
    void setData(int data){
      this->data1 = data;
    }

    void display(){
      cout<<this->data1<<endl;
    }

    friend void swapInteger(C1 &, C2&);
}c1;

class C2{
  int data2;
  public:
    void setData(int data){
      this->data2 = data;
    }

    void display(){
      cout<<this->data2<<endl;
    }

    friend void swapInteger(C1 &, C2&);
}c2;


void swapInteger(C1 &c1, C2 &c2){
  int temp = c1.data1;
  c1.data1 = c2.data2;
  c2.data2 = temp;
}

int main(){
  c1.setData(100);
  c2.setData(10000);
  swapInteger(c1, c2);
  cout<<"C1 -> ";
  c1.display();
  cout<<"C2 -> ";
  c2.display();
  return 0;
}