#include <iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<set>
#include<stack>
#include<cmath>
using namespace std;

class DSU{
    int n;
    int* parent;
    int* rank;
    int* size;

    public:
        DSU(int n):n(n){
            parent = new int[n];
            rank = new int[n];
            size = new int[n];

            for(int i=0; i<n; i++){
                parent[i] = i;
                rank[i] = 1;
                size[i] = 1;
            }
        }
        ~DSU(){
            delete[] size, rank, parent;
        }
        int find_(int x){
            if(x == parent[x]){
                return x;
            }
            return parent[x] = find_(parent[x]);
        }
        void union_rank(int x, int y){
            int xp = find_(x);
            int yp = find_(y);
            if(xp == yp){
                return;
            }
            if(rank[xp]<rank[yp]){
                parent[xp] = yp;
            }else if(rank[yp]<rank[xp]){
                parent[yp]=xp;
            }else{
                parent[xp] = yp;
                rank[yp]++;
            }
        }
        void union_size(int x, int y){
            int xp=find_(x);
            int yp=find_(y);
            if(xp == yp){
                return;
            }
            if(size[xp]<size[yp]){
                parent[xp] = yp;
                size[yp] += size[xp];
            }else{
                parent[yp] = xp;
                size[xp] += size[yp];
            }
        }
};

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node (int x) {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

class Solution {
    public:
    Node* reverseDLL(Node* head) {
        while(!head->next){
            swap(head->next, head->prev);
            head = head->next;
        }
        return head;
    }
    
    void swap(Node*& a, Node*& b) {
        Node* temp = a;
        a = b;
        b= temp;
    }
};

// class test{
//     public:
//         int xy;
//         test(int l):xy(l){}
// }a(2), b(3);

void swap(Node*& a, Node*& b){
    Node* temp = a;
    a=b;
    b=temp;
}

// void swap(test& a, test& b){
//     test temp=a;
//     a=b;
//     b=temp;
// }

// void swap(test* a, test* b){
//     test* temp = a;
//     a = b;
//     b= temp;
// }

// int main(){

    // Node* a= new Node(1);
    // Node* b= new Node(2);
    // Node* c= new Node(3);

    // a->next=b;
    // b->prev=a;
    // b->next = c;
    // c->prev = b;

    // Node* curr = a;
    // // cout<<curr->next<<endl;
    // while(curr->next){
    //     cout<<"Aryan"<<endl;
    //     swap(curr->next, curr->prev);
    //     curr = curr->prev;
    // }

    // swap(curr->next, curr->prev);

    // cout<<c->next->data<<endl;
    // cout<<curr->data<<endl;

    // cout<<a->next->data<<endl;
    // cout<<a->next<<endl;
    // cout<<a->prev<<endl;
    // cout<<a->prev<<endl;
    // cout<<a->data<<endl;
    // cout<<a->next->data<<endl;
    // cout<<a->next->next<<endl;

    // cout<<b->prev<<endl;


    // swap(a->next, a->prev);
    // swap(b->next, b->prev);

    // cout<<endl;
    // unordered_set<pair<int, int>> s;

    // cout<<b->prev<<endl;
    // cout<<b->data<<endl;
    // cout<<b->next->data<<endl;
    // cout<<b->next->next<<endl;

    // cout<<a->next<<endl;
    // cout<<a->prev<<endl;

    // cout<<a->prev->data<<endl;
    // cout<<a->next<<endl;
    // cout<<&a<<endl;

    // test* ptrA = &a;
    // test* ptrB = &b;
    // cout<<"ptrA -> "<<ptrA<<endl;
    // cout<<"ptrA->xy -> "<<ptrA->xy<<endl;
    // cout<<"ptrB -> "<<ptrB<<endl;
    // cout<<"ptrB-xy -> "<<ptrB->xy<<endl;


    // cout<<"a-> "<<&a<<endl;
    // cout<<"b-> "<<&b<<endl;

    // test temp = a;
    // a=b;
    // b=temp;

    

    // int** arr = new int*[10];
    // for(int i=0; i<10; i++){
    //     arr[i] = new int[8];
    //     fill(arr[i], arr[i]+8, INT_MAX);
    // }

    // cout<<arr[0][0]<<endl;

    // for(int i=0; i<10; i++){
    //     delete[] arr[i];
    // }
    // delete[] arr;


    // swap(ptrA, ptrB);
    // a = *ptrA;
    // b = *ptrB;

    // cout<<"a-> "<<&a<<endl;
    // cout<<"b-> "<<&b<<endl;

    // cout<<"ptrA -> "<<ptrA<<endl;
    // cout<<"ptrA->xy -> "<<ptrA->xy<<endl;
    // cout<<"ptrB -> "<<ptrB<<endl;
    // cout<<"ptrB-xy -> "<<ptrB->xy<<endl;

    // cout<<"a -> "<<&a<<endl;
    // cout<<"b -> "<<&b<<endl;

    // vector<int> vec;
    // vec.em

//     multiset<int> ms;
//     ms.insert(4);
//     ms.insert(3);
//     ms.insert(1);
//     ms.insert(4);
//     ms.insert(1);
//     ms.insert(5);

//     auto it = ms.begin();
//     while(it != end(ms)){
//         cout<<(*it)<<endl;
//         it++;
//     }
//     return 0;
// }

class Test{
    public:
        vector<int> NGE(vector<int>& vec){
            int n=vec.size();
            vector<int> ans(n);
            stack<int> st;

            for(int i=0; i<n; i++){
                while(!st.empty() && vec[i]>vec[st.top()]){
                    ans[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }

            while(!st.empty()){
                ans[st.top()] = -1;
                st.pop();
            }

            return ans;
        }
};

int main(){
    int t;
    cin>>t;
    cout<<t<<endl;
    return 0;
}
