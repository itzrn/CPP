#include <iostream>
#include <climits>
#include <vector>
#include <fstream>
#include<string>
using namespace std;


int main() {
    ofstream out;
    out.open("t49_sample.txt");
    out<<"this is me\n";
    out<<"this is me also\n";
    out.close(); // there is also need to close if we are using the object of ifstream

    // to read all the lines until we won't get any line
    ifstream in;
    string str;
    while(in.eof() == 0){
        getline(in, str);
        cout<<str<<endl;
    }
    in.close();
    return 0;
}