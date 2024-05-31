#include<iostream>
using namespace std;

// function protoyping is used to make compiler assure that u need to check further to access the function
int sum(int a, int b); // if you remove and then run the file you will get error, as compiler didn't get the function sum
// the error you will get -> use of undeclared identifier 'sum'
int mult(int, int); // -> this is also acceptable
void print(void); // this is how prototyping of this type of funtion is done, or -> void print();

int main(){
  // num1 and num2 are actual parameter
  int num1, num2;
  cout<<"Enter num1 ->";
  cin>>num1;
  cout<<"Enter num2 -> ";
  cin>>num2;
  cout<<"Sum of a nd b -> "<<sum(num1, num2)<<endl;
  return 0;
}

int sum(int a, int b){
  return a+b;
}

int mult(int a, int b){
  // here a and b are formal parameter which takes value from actual parameter
  return a*b;
}

void print(){
  cout<<"Hello World"<<endl;
}