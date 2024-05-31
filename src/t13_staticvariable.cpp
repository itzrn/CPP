#include<iostream>
using namespace std;
int sum(int a, int b){
  static int c=0; // static variable is a variable whcih function never forget
  c++; // that is the reason the value of c will get change on evry call of this function
  return a+b+c;
}
int main(){
  int a, b;
  cout<<"Enter the value of a and b"<<endl;
  cin>>a>>b;


  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;
  cout<<"Sum -> "<<sum(a, b)<<endl;

  return 0;
}