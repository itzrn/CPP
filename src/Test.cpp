#include <bits/stdc++.h>
// #include <chrono>
#include <iostream>
using namespace std;
// using namespace std::chrono;


class Singleton {
private:
    static Singleton* instance; // Static member variable to hold the single instance
    static mutex mtx;      // Mutex for thread safety

    // Private constructor to prevent instantiation from outside
    Singleton() {
    }
    

public:
    // Delete copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static member function to get the Singleton instance
    static Singleton* getInstance() {
        lock_guard<std::mutex> lock(mtx); // Ensure thread safety
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

struct n{
    n* child[26]={NULL};
    bool isword=false;
};


int main() {
    // vector<int> vec = {1, 2 ,3, 4};
    // vector<int> vec2 = {8, 7, 6, 5};
    // vec.insert(end(vec), begin(vec2), end(vec2));
    // int n=-89;
    // int b = 413;

    n root;
    cout<<&root<<endl;

    // cout<<(n%b)<<endl;

    // for(int i:vec){
    //     cout<<i<<endl;
    // }

    // vector<pair<int, int>> vec;
    // vec.emp

    // unordered_map<int, int>mp;
    // end(mp);
    // priority_queue<int> pq;

    // stack<int>st;
    

    return 0;
}





// struct Node{
//     int data;
//     Node* left;
//     Node* right;
//     Node(){}
//     Node(int data):data(data), left(nullptr), right(NULL){}
// };

// void presucc(Node* root, Node*& pre, Node*& succ, int& k){
//     if(!root){
//         return;
//     }
//     if((*root).data<k){
//         pre=root;
//         presucc((*root).right, pre, succ, k);
//     }else if((*root).data>k){
//         succ=root;
//         presucc((*root).left, pre, succ, k);
//     }else{
//         presucc((*root).left, pre, succ, k);
//         presucc((*root).right, pre, succ, k);
//     }
// }

// Node* treeBuild(string str){
//     if(str.empty() || str[0]=='N'){
//         return NULL;
//     }
//     // to read each word from the string
//     // string str = "Hello world! kaisa ho?"
//     istringstream iss(str);
//     vector<string> word;
//     for(string i;iss>>i;){
//         word.push_back(i);
//     }

//     Node* root = new Node(stoi(word[0]));
//     int n=word.size();
//     int i=1;
//     queue<Node*> qu;
//     qu.push(root);

//     while (i<n && !qu.empty()) {
//         Node* curr = qu.front();
//         qu.pop();
//         if(i<n && word[i] != "N"){
//             (*curr).left = new Node(stoi(word[i]));
//             qu.push((*curr).left);
//         }
//         i++;

//         if(i<n && word[i] != "N"){
//             (*curr).right = new Node(stoi(word[i]));
//             qu.push((*curr).right);
//         }
//         i++;
//     }

//     return root;
// }

// void inorder(Node* root){
//     if(!root){
//         return;
//     }

//     inorder((*root).left);
//     cout<<(*root).data<<" ";
//     inorder((*root).right);
// }

// int MinSize(vector<int> A, int n) {
//     unordered_map<int, int> mp;
//     for(int& i:A){
//         mp[i]++;
//     }
    
//     auto its = begin(mp);
//     auto ite = end(mp);
    
//     while(its != ite){
//         if((*its).second == (*ite).second){
//             its++;
//             // ite--;
//         }else if((*its).second > (*ite).second){
//             (*its).second -= (*ite).second;
//             // ite--;
//         }else{
//             (*ite).second -= (*its).second;
//             its++;
//         }
//     }
    
//     return (*its).second;
// }


// int lca(Node* root, int& p, int& q){
//     if(!root){
//         return -1;
//     }

//     if((*root).data == p || (*root).data == q){
//         return (*root).data;
//     }
//     int left = lca((*root).left, p, q);
//     int right = lca((*root).right, p, q);

//     if(left != -1 && right != -1){
//         return (*root).data;
//     }else if(left != -1){
//         return left;
//     }else if (right != -1) {
//         return right;
//     }
//     return -1;
// }


// int main(int argc, char const *argv[]) {

//     // int** arr = new int*[10];
    
//     // string str = "10 20 30 40  60 N N N N N  N  ";
//     // Node* root = treeBuild(str);
//     // inorder(root);

//     vector<int> a= {3,1,4,7,3,1,2,9,1};
//     cout<<*lower_bound(begin(a), end(a), 5)<<endl;
//     return 0;
// }


