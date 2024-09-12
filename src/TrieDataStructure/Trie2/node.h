#ifndef NODE_H
#define NODE_H

#include <unordered_map>
using namespace std;
class node{
    unordered_map<char, node*> mp;
    int cew;
    int cp;
    node():cew(0), cp(0){}
};
#endif