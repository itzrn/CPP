#include<iostream>
#include<string>
using namespace std;

class binary{
  string s; // this attribut is private, by default compiler take it as private

  public:
    void read(void);
    bool chk_bin();
    string getString();
    void onesComplement(void);
};

void binary :: read(){
  cout<<"Enter a Binary Number ->"<<endl;
  cin>>s; // this s is getting direct call from the class
}


bool binary :: chk_bin(void){
  int n=s.length();
  for(int i=0; i<n; i++){
    if(s.at(i) != '0' && s.at(i) != '1'){
      return false;
    }
  }

  return true;
}

string binary :: getString(){
  return s;
}

void binary :: onesComplement(){
  int n=s.length();
  for(int i=0; i<n; i++){
    if(s.at(i) == '0'){
      s.at(i) = '1';
    }else{
      s.at(i) = '0';
    }
  }
}

int main(){
  /*
  class -> this is the extension of struct in cpp
  limitation of struct -> 
            members are public
            no method can be written in struct

  classes -> struct  more
            can have method and properties
            can make few members as private and few as public
            object can be declare along with the class declaration

            class Employee{
                // define this class
            }aryan, harry;
  */

  binary b;
  b.read();
  cout<<"The given string \""<<b.getString()<<"\" is binary -> "<<b.chk_bin()<<endl;
  b.onesComplement();
  cout<<"Ones Complement -> "<<b.getString()<<endl;

  /*
  nesting of function is just calling a function in another function
  */
  return 0;
}

