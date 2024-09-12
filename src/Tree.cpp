#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <list>
#include <string.h>
#include <algorithm>
#include <cctype>
#include <cfloat>
// #define long long as ll
using namespace std;


class Tree{
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(){}
        Node(int data):data(data), left(nullptr), right(nullptr){}
    };
    public:
        Tree(){}
        Node* treeBuild(vector<int>& vals){
            if(vals.empty() || vals[0] == -1){
                return nullptr;
            }
            int n=vals.size();
            Node* root = new Node(vals[0]);
            queue<Node*> qu;
            qu.emplace(root);
            int idx = 1;
            while(!qu.empty()){
                Node* temp = qu.front();
                qu.pop();

                if(idx<n && vals[idx] != -1){
                    (*temp).left = new Node(vals[idx]);
                    qu.emplace((*temp).left);
                }
                idx++;

                if(idx<n && vals[idx] != -1){
                    (*temp).right = new Node(vals[idx]);
                    qu.emplace((*temp).right);
                }
                idx++;
            }

            return root;
        }
        void printPreorder(Node* root){
            if(!root){
                return;
            }

            cout<<(*root).data<<endl;

            printPreorder((*root).left);
            printPreorder((*root).right);
        }
        vector<int> topView(Node *root) {
            vector<int> ans;
            if(root == NULL){
                return ans;
            }
            
            map<int, int> mp;
            queue<pair<Node*, int>> qu;
            
            qu.push({root, 0}); // or -> qu.push(make_pair(root, 0));
            while(!qu.empty()){
                auto [node, level] = qu.front(); // this feature of c++ is only available in c++ 14 or above
                qu.pop();
                
                // Node* node=it.first;
                // int level = it.second;
                
                if(mp.find(level)==mp.end()){
                    mp[level]=(*node).data;
                }
                
                if((*node).left){
                    qu.push(make_pair((*node).left, level-1));
                }
                
                if((*node).right){
                    qu.push(make_pair((*node).right, level+1));
                }
            }
            
            
            for(auto it:mp){// this gives pair
                ans.push_back(it.second);
            }
            
            return ans;
        }
        bool isSameTree(Node* p, Node* q) {
            if(!p && !q){
                return true;
            }
            if(!p || !q || (*p).data != (*q).data){
                return false;
            }
            return isSameTree((*p).left, (*q).left) && isSameTree((*p).right, (*q).right);
        }
        void diagonalTraversal(vector<vector<int>>& ans, Node* root, int left){
        if(!root){
            return;
        }
        if(ans.size()<=left){
            ans.push_back({(*root).data});
        }else{
            ans[left].push_back((*root).data);
        }
        diagonalTraversal(ans, (*root).left, left+1);
        diagonalTraversal(ans, (*root).right, left);
    }
        int kthAncestor(Node* root, int& node, int& k, Node*& ans){
            if(!root){
                return 0;
            }

            if((*root).data == node){
                return 1;
            }

            int left = kthAncestor((*root).left, node, k, ans);
            int right = kthAncestor((*root).right, node, k, ans);
            if(left == k || right == k){
                ans = root;
            }

            if(left != 0){
                return 1+left;
            }
            if(right!=0){
                return 1+right;
            }
            return 0;
        }
        void inorder(Node* root){
            if(!root){
                return;
            }

            inorder((*root).left);
            cout<<(*root).data<<" ";
            inorder((*root).right);
        }
        bool searchBST(Node* root, int& key){
            if(!root){
                return false;
            }
            if((*root).data == key){
                return true;
            }
            return searchBST((*root).left, key) || searchBST((*root).right, key);
        }
        Node* insertBST(Node* root, int key){
            if(!root){
                return new Node(key);
            }

            if((*root).data == key){
                return root;
            }

            if((*root).data>key){
                (*root).left = insertBST((*root).left, key);
            }else{
                (*root).right = insertBST((*root).right, key);
            }

            return root;
        }
        Node* deleteBST(Node* root, int key){
            if(!root){
                return NULL;
            }
            if((*root).data == key){
                if(!(*root).left){
                    return (*root).right;
                }else if(!(*root).right){
                    return (*root).left;
                }else{
                    Node* temp = (*root).right;
                    while((*temp).left){
                        temp = (*temp).left;
                    }
                    (*temp).left = (*root).left;
                    return (*root).right;
                }
            }

            if((*root).data>key){
                (*root).left = deleteBST((*root).left, key);
            }else{
                (*root).right = deleteBST((*root).right, key);   
            }
            return root;
        }
};

int main()
{
    Tree tree;


    // 1. diagonalTraversal
    // vector<int> vec = {8,3,10,1,-1,6,14,-1,-1,4,7,13,-1,-1,-1,-1,-1,-1,-1};
    // Node* root = tree.treeBuild(vec);
    // tree.printPreorder(root);
    // vector<vector<int>> ans;
    // tree.diagonalTraversal(ans, root, 0);
    // for(auto& i:ans){
    //     for(int& j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }



    // 2. Topview
    // vector<int> vec = {34, 25, 54, 22, 29, 47, 77, 2, 24, 26, 30, 41, 48, 72, 96, 1, 20, 23, -1, -1, 28, -1, 33, 35, 42, -1, 50, 66, 75, 90, -1, -1, -1, 3, 21, -1, -1, 27, -1, 32, -1, -1, 37, -1, 45, 49, 52, 63, 68, 74, 76, 82, 95, -1, 17, -1, -1, -1, -1, 31, -1, 36, 38, 44, 46, -1, -1, 51, 53, 56, 65, 67, 70, 73, -1, -1, -1, 81, 83, 92, -1, 8, 18, -1, -1, -1, -1, -1, 40, 43, -1, -1, -1, -1, -1, -1, -1, 55, 60, 64, -1, -1, -1, 69, 71, -1, -1, 80, -1, -1, 86, 91, 93, 7, 13, -1, 19, 39, -1, -1, -1, -1, -1, 59, 62, -1, -1, -1, -1, -1, -1, 78, -1, 85, 89, -1, -1, -1, 94, 6, -1, 9, 16, -1, -1, -1, -1, 58, -1, 61, -1, -1, 79};
    // Node* root = tree.treeBuild(vec);
    // vector<int> ans = tree.topView(root);

    // for(int& i: ans){
    //     cout<<i<<endl;
    // }


    // 3. kthAncestor
    // vector<int> vals = {1, 2, 3, 4, 5, -1 ,-1};
    // Node* root = tree.treeBuild(vals);
    // Node* ans = NULL;
    // int k=2;
    // int node = 5;
    // tree.kthAncestor(root, node, k, ans);
    // if(ans){
    //     cout<<ans->data<<endl;
    // }



    // 4. insert, delete, search in BST
    // Node* root=NULL; 
    // root = tree.insertBST(root, 8);
    // tree.insertBST(root, 3);
    // tree.insertBST(root, 10);
    // tree.insertBST(root, 1);
    // tree.insertBST(root, 6);
    // tree.insertBST(root, 14);
    // tree.insertBST(root, 4);
    // tree.insertBST(root, 7);
    // tree.insertBST(root, 13);
    // tree.inorder(root);
    // cout<<endl;
    // root = tree.deleteBST(root, 8);
    // tree.inorder(root);


    






    // list<int>* a;
    // a = new list<int>[10];

    // if((*a).begin() == (*a).end()){
    //     cout<<"Aryan"<<endl;
    // }

    return 0;
}