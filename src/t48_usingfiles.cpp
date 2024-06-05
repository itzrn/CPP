#include<iostream>
#include<fstream>
using namespace std;

/*
These are some useful classes for working with files in C++
fstreambase
    ifstream --> derived from fstreambase
    ofstream --> derived from fstreambase

with the help of above class we can read and write the file

in order to work with files in c++, you will have to open it. Primarily, there are 2 ways to open the file:
1. using the constructor
2. using member function open() of the class
*/

int main(){
    string str1 = "aryan";
    string str2;
    // openning file suing constructor
    // ofstream out("t48_sample.txt"); // this helps to write somrting to text file
    // out<<str1;

    ifstream in("t48_sampleread.txt");
    // in>>str2; // this line will give only first word of the file

    // to read the line
    getline(in, str2);
    // getline(in, str2); // the number of time you run this line you will get thenext line
    cout<<str2<<endl;
    return 0;
}