#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val):val(val){}
};

int main() {
    Node *ptr=nullptr;
    Node n = Node(2);
    // ptr = &n;
    if(ptr){
        cout<<"true"<<endl;
        cout<<ptr->val<<endl;
    }else {
        cout<<"false"<<endl;
    }
    string a = "Aryan";
    cout<< *a.begin() <<endl;
    
    
    return 0;
}