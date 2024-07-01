#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(){}
    Node(int data):data(data), left(nullptr), right(NULL){}
};

void presucc(Node* root, Node*& pre, Node*& succ, int& k){
    if(!root){
        return;
    }
    if((*root).data<k){
        pre=root;
        presucc((*root).right, pre, succ, k);
    }else if((*root).data>k){
        succ=root;
        presucc((*root).left, pre, succ, k);
    }else{
        presucc((*root).left, pre, succ, k);
        presucc((*root).right, pre, succ, k);
    }
}

Node* treeBuild(string str){
    if(str.empty() || str[0]=='N'){
        return NULL;
    }
    // to read each word from the string
    // string str = "Hello world! kaisa ho?"
    istringstream iss(str);
    vector<string> word;
    for(string i;iss>>i;){
        word.push_back(i);
    }

    Node* root = new Node(stoi(word[0]));
    int n=word.size();
    int i=1;
    queue<Node*> qu;
    qu.push(root);

    while (i<n && !qu.empty()) {
        Node* curr = qu.front();
        qu.pop();
        if(i<n && word[i] != "N"){
            (*curr).left = new Node(stoi(word[i]));
            qu.push((*curr).left);
        }
        i++;

        if(i<n && word[i] != "N"){
            (*curr).right = new Node(stoi(word[i]));
            qu.push((*curr).right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root){
    if(!root){
        return;
    }

    inorder((*root).left);
    cout<<(*root).data<<" ";
    inorder((*root).right);
}

int MinSize(vector<int> A, int n) {
    unordered_map<int, int> mp;
    for(int& i:A){
        mp[i]++;
    }
    
    auto its = begin(mp);
    auto ite = end(mp);
    
    while(its != ite){
        if((*its).second == (*ite).second){
            its++;
            // ite--;
        }else if((*its).second > (*ite).second){
            (*its).second -= (*ite).second;
            // ite--;
        }else{
            (*ite).second -= (*its).second;
            its++;
        }
    }
    
    return (*its).second;
}


int main(int argc, char const *argv[]) {

    int** arr = new int*[10];
    
    string str = "10 20 30 40  60 N N N N N  N  ";
    Node* root = treeBuild(str);
    inorder(root);
    return 0;
}


