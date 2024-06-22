#include<iostream>
using namespace std;
#include<string>

int main(){
    int a=10;
    int *ptr = &a;

    // *ptr = 999; doing this will change the value of a also

    cout<<"The address of a(or ptr) -> "<<ptr<<endl;
    cout<<"The value at a(or ptr) -> "<<*ptr<<endl; // *ptr -> is dereferencing the pointer variable, means taking out the value at reference

    // new keyword
    int *p = new int(3); // this is the way to initialize a pointer with any address, same for all other data types
    cout<<"The value at address at p is -> "<<*p<<endl;

    // new way to have integer array
    int *arr = new int[3]; // this array creted with garbage value initialized
    arr[0]=10;
    arr[1]=20; // this can also be written as -> *(arr+1) = 20
    arr[2]=30;

    cout<<"The value of arr[0] -> "<<arr[0]<<endl;
    cout<<"The value of arr[1] -> "<<arr[1]<<endl;
    cout<<"The value of arr[2] -> "<<arr[2]<<endl;

    //delete operator
    delete[] arr; // this is the way to delete the contiguious block
    // after delete there is no guranty that the value at each index remain same as of before
    cout<<"The value of arr[0] -> "<<arr[0]<<endl;
    cout<<"The value of arr[1] -> "<<arr[1]<<endl;
    cout<<"The value of arr[2] -> "<<arr[2]<<endl;

    return 0;
}