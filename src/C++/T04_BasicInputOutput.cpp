#include<iostream>
using namespace std;

int sum(int a, int b){
  return a+b;
}

int main()
{
  int num1, num2;
   // << is called insertion operator
   // >> is called Extraction operator

   cout<<"Enter the value of num1: \n";
   cin>>num1;

   cout<<"Enter the value of num2: \n";
   cin>>num2;

   cout<<"The sum is -> "<<sum(num1, num2)<<endl; // endl is used to add new line
  return 0;
}
