#include <iostream>
#include <climits>
#include <set>
#include<string.h>
#include <vector>
using namespace std;

struct Node{
    Node* links[26];
    bool flag;

    Node(bool flag):flag(flag){
        memset(this->links, 0, 26);
    }

    bool contains(char ch){
        return this->links[ch-'a'] != 0;
    }

    void put(char ch, Node* node){
        this->links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        this->flag = true;
    }
    
    bool getEnd(){
        return this->flag;
    }
};

class Solution {
    Node* root;
public:
    Solution(){
        this->root = new Node(false);
    }

    void insert(string str){
        Node* node = this->root;
        int n=str.length();

        for(int i=0; i<n; i++){
            if(!node->contains(str[i])){
                node->put(str[i], new Node(false));
            }
            node = node->get(str[i]);
        }

        cout<<"Aryan"<<endl;
        node->setEnd();
        cout<<"Aryan1"<<endl;
    }

    string search(string str){
        Node* node = root;
        int n=str.size();
        string result;
        for(char c:str){
            if(!node->contains(c)){
                return str;
            }
            result += c;
            if(node->get(c)->getEnd()){
                return result;
            }

            node = node->get(c);
        }

        return str;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string word:dictionary){
            insert(word);
        }

        // stringstream ss(sentence);
        // string word, res;
        // while(ss >> word){ // this is the way to extraxt word from the string sentence
        //     if(!res.empty()){
        //         res += " ";
        //     }

        //     res += search(word);
        // }

        return "res";
    }
};
#include<sstream>
int main(int argc, char const *argv[])
{
    // string sentence = "             Aryan           Prajapati       21BCE7170         ";
    // stringstream ss(sentence);
    // string word;
    // while(ss >> word){ // this is the way to extraxt word from the string sentence
    //     cout<<word<<endl;
    //     // if(!res.empty()){
    //     //     res += " ";
    //     // }

    // }

    set<int> set_a;
    set_a.insert(2);
    set_a.insert(4);
    set_a.insert(1);
    set_a.insert(7);
    set_a.insert(3);
    set_a.insert(0);
    set<int> :: iterator ita=set_a.begin();
    set<int>::iterator itaaaa = set_a.insert(10).first;
    while(ita != set_a.end()){
        
        cout<<*ita<<endl;
        ita++;
    }
    set<int> set_b;

    set_b.insert(set_a.begin(), set_a.end());

    set<int> :: iterator itb=set_b.begin();
    while(itb != set_b.end()){
        
        cout<<*itb<<endl;
        itb++;
    }

    
    return 0;
}
