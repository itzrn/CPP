#include<iostream>
using namespace std;

// first write all the compulsory argument then write all default argument 
float money_received(int current, float factor=1.04){ // here factor will work as default parameter
  // if you give only one parameter to this function then also it will work or you can give max to max two argument

  return current*factor ;
}

int main(){

  return 0;
}

// you can look for constant argument 