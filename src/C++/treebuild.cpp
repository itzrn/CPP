#include <iostream>
#include <climits>
#include<queue>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val):val(val), left(nullptr), right(nullptr){}
};

class Tree{
    Node* root;
    private:
        void pre_order(Node* root){
            if(!root){
                return;
            }
            cout<<root->val<<endl;
            pre_order(root->left);
            pre_order(root->right);
        }

    public:
        Tree(){
            this->root = nullptr;
        }

        void build(vector<int>& value){
            if(value.empty()){
                return;
            }
            int n=value.size();
            root = new Node(value[0]);
            queue<Node*> queue_;
            queue_.push(root);
            int i=1;
            while(!queue_.empty()){
                Node* temp = queue_.front();
                queue_.pop();
                if(i<n && value[i] != -1){
                    temp->left=new Node(value[i]);
                    queue_.push(temp->left);
                }
                i++;
                if(i<n && value[i] != -1){
                    temp->right = new Node(value[i]);
                    queue_.push(temp->right);
                }
                i++;
            }
        }

        void print(){
            pre_order(this->root);
        }

};

// int main() {

//     // Tree tree;
//     // Tree* tree = new Tree();
//     Tree tree = Tree();
//     int n;
//     cin>>n;
//     vector<int> vec;
//     for(int i=0; i<n; i++){
//         int a;
//         cin>>a;
//         vec.push_back(a);
//     }

//     tree.build(vec);
//     cout<<"Prinitng PreOrder"<<endl;
//     tree.print();
    
    
//     return 0;
// }

int main(int argc, char const *argv[]) {
    char str[] = "Aryan Prajapati";
    cout<<str[0]<<endl;
    return 0;
}
