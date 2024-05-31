#include<iostream>
#include<string>
using namespace std;


class Employee{
  int id;
  int salary;

  public:
    void setId(void){
      this->salary=122; // this i am setting for all employee
      cout<<"Enter the Id of the Employee ->"<<endl;
      cin>>this->id;
    }

    void getId();
} ;

void Employee :: getId(){
  cout<<"The Id of the Employee is -> "<<this->id<<endl;
}

int main(){
  // making array of object

  Employee fb[4];
  for(int i=0; i<4; i++){
    fb[i].setId();
    fb[i].getId();
  }
  return 0;
}