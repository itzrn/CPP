#include <iostream>
#include <climits>
#include <vector>
#include <fstream>
using namespace std;


int main() {
    ofstream hout("t49_sample.txt");
    cout<<"Enter a line"<<endl;
    string line="Aryan";

    hout<<line;
    hout.close(); // this is used to break the link between compiler and file
    return 0;
}