#include <iostream>
#include <string.h>
using namespace std;

struct Node{ // in struct by default attributes or functions are public
    Node* links[26];
    bool flag;

    Node(bool flag):flag(flag){
        memset(links, 0, sizeof(links)); // this is a way to initialize arry of object with NULL or nulptr
    }

    bool contains(char ch){
        return links[ch-'a'] != 0;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        this->flag = true;
    }

    bool isEnd(){
        return this->flag;
    }
};

class Trie{ // in class functions and attributes as default are private
    private:
        Node* root;
    public:
        Trie(){
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

            node->setEnd();
        }

        bool search(string str){
            Node* node = this->root;
            int n = str.length();
            for(int i=0; i<n; i++){
                if(!node->contains(str[i])){
                    return false;
                }

                node = node->get(str[i]);
            }

            return node->isEnd();
        }

        bool startWith(string str){
            Node* node = this->root;
            int n=str.size();

            for(int i=0; i<n; i++){
                if(!node->contains(str[i])){
                    return false;
                }
                node = node->get(str[i]);
            }

            return true;
        }
};

int main() {
    Trie tr;
    tr.insert("aryan");
    tr.insert("dharamendra");
    tr.insert("manoj");
    tr.insert("ashmit");
    cout<<tr.startWith("ar")<<endl;
    return 0;
}
