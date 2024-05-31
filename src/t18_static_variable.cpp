#include<iostream>
#include<string>
using namespace std;


class Employee{
  int id;
  static int count; // where a static variable is created, by default it get initialize with '0'

  public:
    void setData(){
      cout<<"Enter the id"<<endl;
      cin>>id;
      count++;
    }

    void getData(){
      cout<<"The if of this Employee is "<<id<<" and Employee number id "<<count<<endl;
    }
}aryan, anup, nayan;

// this static variable get connect with class, thats y static variable is also called class variable
// so this the property of class, jitne object bante cahal jyenga utna count bhadh jyega
// this is called static data member
int Employee :: count; // Default value will be zero, here we can update the defalult value of static but in the class
// doing int Employee :: count=100; here is permitted
int main(){

  aryan.setData();
  aryan.getData();

  anup.setData();
  anup.getData();

  nayan.setData();
  nayan.getData();
  
  return 0;
}