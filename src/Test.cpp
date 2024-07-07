#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


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

int main() {
    // using namespace std::chrono;
    // auto i =high_resolution_clock::now();
    // auto j =high_resolution_clock::now();
    // auto end = duration_cast<microseconds>(j-i);
    // Singleton* obj1 = Singleton::getInstance();
    // Singleton* obj2 = Singleton::getInstance();

    // std::cout << (obj1 == obj2) << std::endl; // Outputs: 1 (true)

    string str ="abcdef";
    cout<<str.substr(5, 1)<<endl;

    int a=2500000000;

    return 0;
}





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


int lca(Node* root, int& p, int& q){
    if(!root){
        return -1;
    }

    if((*root).data == p || (*root).data == q){
        return (*root).data;
    }
    int left = lca((*root).left, p, q);
    int right = lca((*root).right, p, q);

    if(left != -1 && right != -1){
        return (*root).data;
    }else if(left != -1){
        return left;
    }else if (right != -1) {
        return right;
    }
    return -1;
}


// int main(int argc, char const *argv[]) {

//     // int** arr = new int*[10];
    
//     // string str = "10 20 30 40  60 N N N N N  N  ";
//     // Node* root = treeBuild(str);
//     // inorder(root);

//     vector<int> a= {3,1,4,7,3,1,2,9,1};
//     cout<<*lower_bound(begin(a), end(a), 5)<<endl;
//     return 0;
// }


