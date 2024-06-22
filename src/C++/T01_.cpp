// include means importing smething in the file like we do in java
#include <iostream> // this import is used to input output(like printing somting on the console) the data
using namespace std; // this std file contains cout function, thats the reason we import it to use cout

int main(){ // this is the entry point of the cpp file like main function of java
  int a; // variable declaration
  a = 12; // initialisation

  cout<<"Size of int -> "<< sizeof(a) <<" Byte"<< endl;

  float b;
  cout<<"Size of float -> "<< sizeof(b) <<" Byte"<< endl;

  char c;
  cout<<"Size of char -> "<< sizeof(c) <<" Byte"<< endl;

  bool d;
  cout<<"Size of bool -> "<< sizeof(d) <<" Byte"<< endl;

  short e;
  cout<<"Size of short -> "<< sizeof(e) <<" Byte"<< endl;

  /*
    Type Modifiers
    signed -> 4 bytes -> -2,147,483,647 to 2,147,483,647

    unsigned -> 4 bytes -> 0 to 4,294,967,295

    long -> 8 bytes -> -9223372036854775808 to 9223372036854775807

    short -> 2 bytes -> -32768 to 32767
  */

 short int si;
 long int li;

 cout<<"Size of short int -> "<< sizeof(si) <<" Byte"<< endl;
 cout<<"Size of long int -> "<< sizeof(li) <<" Byte"<< endl;

 return 0; // the main function have return type int just to make operating system to know that the file have executed properly or not
 // if it return other than 0 means OS will get instruction that that there is any error int the program while running it.


 // low level lang -> very close to hardware, cpp is a low lwvwl language
 // high level lang -> far form hardware
}