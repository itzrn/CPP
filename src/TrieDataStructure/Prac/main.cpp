#include "trie.h"
#include <iostream>
using namespace std;

int main() {    

    trie tr;
    string aryan = "aryan";
    string nayan = "nayan";
    string anup = "anup";

    tr.insert(aryan);
    tr.insert(nayan);
    tr.insert(anup);
    string st="ar";
    cout<<tr.start_with(st)<<endl;

    cout<<"Aryan"<<endl;
    int a;
    cin>>a;
    cout<<"Aryan"<<endl;

    return 0;
}

