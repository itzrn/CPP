#ifndef NODE_H
#define NODE_H

#include <unordered_map>
using namespace std;

// template <class T>
struct node{
    unordered_map<char, node*> mp; 
    // let if any key is not present in map and trying to access the value of it then it will give nullptr
    bool flag;
    node():flag(false){}
};

#endif