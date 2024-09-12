#ifndef TRIE_H
#define TRIE_H

#include "node.h"
#include <string>
using namespace std;

class trie{
private:
    node* root;
public:
    trie():root(new node()){}
    void insert(string& word){
        node* temp = root;
        for(int i=0; i<word.length(); i++){
            if(!(*temp).mp[word[i]]){
                (*temp).mp[word[i]]=new node();
            }
            temp = (*temp).mp[word[i]];
        }
        (*temp).flag = true;
    }

    bool search(string& word){
        node* temp = root;
        for(int i=0; i<word.length() && temp; i++){
            temp = (*temp).mp[word[i]];
        }
        return temp?(*temp).flag:false;
    }

    bool start_with(string& str){
        node* temp = root;
        for(char ch:str){
            if(!temp){
                return false;
            }
            temp = (*temp).mp[ch];
        }
        return true;
    }
};


#endif