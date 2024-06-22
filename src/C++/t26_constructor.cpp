#include<iostream>
#include<string>
using namespace std;

class Test{
  int a, b;
  public:
    /*
    Creating a constructor
    Constructor is a special member function with the same name as of class
    It is used to initialize the object of a class
    It is automatically invoked whenever an object is created
    Constructor should be decalre in the public section of the class
    Do not have return type
    we canot refer to there address
    */
    // Test(void){
    //   cout<<"This is a Default Constructor"<<endl;
    // }

    Test(void);
    Test(int a, int b){
      this->a = a;
      this->b = b;
      cout<<"a -> "<< this->a <<endl;
      cout<<"b -> "<< this->b <<endl;
    }
}x(1, 2), y;

Test :: Test(void){ // either we can write the body of the constructor here or in the class itself
  cout<<"This is a Default Constructor"<<endl;
}

int main(){
  Test a(1,4); // implicite call
  Test b = Test(10,12); // explicit call
  return 0;
}