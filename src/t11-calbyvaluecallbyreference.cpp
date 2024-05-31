#include<iostream>
using namespace std;

void swap(int, int);
void swapPointer(int*, int*);
void swapReferenceVar(int &, int &);
int* update(int* a);
int& update(int &a);

int main(){
   int a=4, b=5;

   cout<<"Swapping using swap function"<<endl; // this is cal by value
   cout<<"Value of a -> "<<a<<" Valur of b -> "<<b<<endl;
   swap(a, b);
   cout<<"Value of a -> "<<a<<" Valur of b -> "<<b<<endl;

   cout<<endl;

   cout<<"Using swapPointer function"<<endl; // this is call by reference
   cout<<"Value of a -> "<<a<<" Valur of b -> "<<b<<endl;
   swapPointer(&a, &b);
   cout<<"Value of a -> "<<a<<" Valur of b -> "<<b<<endl;

   cout<<endl;

   cout<<"Using reference variable"<<endl;
   cout<<"Value of a -> "<<a<<" Valur of b -> "<<b<<endl;
   swapReferenceVar(a, b);
   cout<<"Value of a -> "<<a<<" Valur of b -> "<<b<<endl;

   cout<<endl;
   cout<<"Updating value"<<endl; // this update the value by going to its address
   *update(&a) = 89;
   cout<<"Updated value of a->"<<a<<endl;

   cout<<endl;
   cout<<"Updating value"<<endl;
   update(b) = 100;
   cout<<"Updated value of b ->"<<b<<endl;
  return 0;
}

// as here a and b is formal parameter, after providing actual parameter, the value o actual parameter will get copt to formal parameter
// and there will not be any change in actual parameter
void swap(int a, int b){ // this function will swap the value of a and b
  int temp = a;
  a = b;
  b = temp;
}

void swapPointer(int* a, int* b){ // this function will swap the value present at address a and b
  int temp = *a;
  *a = *b;
  *b = temp;
}

void swapReferenceVar(int &a, int &b){ // using reference variable
  int temp = a;
  a = b;
  b = temp;
}

int* update(int* a){ // this function return the pointer of any variable
  return a;
}

int& update(int &a){// this function return the address(reference) of any variable
  return a;
}