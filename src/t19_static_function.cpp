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

    static void getCount(){// this can only access static variable
      // if there is any variable not static then writting here in this function will give error
      // means as we saw in java we can not access non static variable or function in static function
      cout<<"The value of count is "<<count<<endl;
    }
}aryan, anup, nayan;

int Employee :: count;


int main(){

  aryan.setData();
  aryan.getData();
  Employee :: getCount();


  anup.setData();
  anup.getData();
  Employee :: getCount();

  nayan.setData();
  nayan.getData();
  Employee :: getCount();
  
  return 0;
}