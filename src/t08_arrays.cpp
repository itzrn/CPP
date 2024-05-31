#include<iostream>
using namespace std;

int main(){
  int marks[] = {1,2,3,4}; // or int marks[4] = {1,2,3,4};, cpp compiler can automatically detect the size of array
  // here name of array is only the address, doing &marks is wrong


  //like this we can dereference the array and use it
  int*p = marks; // now p is working as pointer for marks array, *p -> marks[0], *(p+1) -> marks[1] ...
  // *(p++) -> marks[0], *(p++) -> marks[1], and also doing this p address increases by (4 byte) so *p -> marks[2]
  cout<<"Printing one element of the array -> "<<*(p+1)<<endl; // this is also a way to access any index value
  //newAddress = currentAddress + i*size(data type)
  //marks+i = marks + i*(4 byte)
  return 0;
}