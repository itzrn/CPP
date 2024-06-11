#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <string.h>
using namespace std;


class Solution {


    int dp[1001][1001];
    int **a;

    int recursion(string str1, int idx1, int n, string str2, int idx2, int m){
        if(idx1 == n || idx2 == m){
            return 0;
        }


        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }

        if(str1[idx1] == str2[idx2]){
            return dp[idx1][idx2] = 1 + recursion(str1, idx1+1, n, str2, idx2+1, m);
        }

        int temp1 = recursion(str1, idx1+1, n, str2, idx2, m);
        int temp2 = recursion(str1, idx1, n, str2, idx2+1, m);

        return dp[idx1][idx2] = max(temp1, temp2);
    }
public:
    int* count(string& str){
        int *arr = new int[26];
        for(char ch:str){
            arr[ch-'a']++;
        }
        return arr;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        memset(dp, -1, sizeof(dp));
        int ans = recursion(text1, 0, n, text2, 0, m);
        return ans == -1?0: ans;
    }

    int** xyz(){
        a = new int*[10];
        for(int i=0; i<10; i++){
            a[i] = new int[12]{};
        }

        for(int i=0; i<10; i++){
            for(int j=0; j<12; j++){
                cout<<a[i][j]<<" ";
            }   
            cout<<endl;
        }

        for(int i=0; i<10; i++){
            delete a[i];
        }
        delete a;
        return a;
    }
}s;

int main(){
    // int arr[10];
    // memset(arr, -1, sizeof(arr));
    // int **arr = s.xyz();
    // cout<<"Aryan"<<endl;
    // for(int i=0; i<10; i++){
    //     for(int j=0; j<12; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // string str = "aryanaryan";
    // int *arr = new int[26]{};
    // for(int i=0; i<str.length(); i++){
    //     if(str[i]>=97 && str[i]<=122){
    //         arr[str[i]-'a']++;
    //     }
    // }

    // for(int i=0; i<26; i++){
    //     cout<<arr[i]<<endl;
    // }

    set<int> set_;
    set_.insert(5);
    set_.insert(1);
    set_.insert(4);
    set_.insert(3);
    set_.insert(2);
    set_.insert(1);

    set<int> :: iterator it = set_.begin();
    // set<int> :: iterator ite = set_.end();


    while(it!=prev(set_.end())){
        // if((*it+1)-*it == 1){

        // }
        cout<<*it<<" "<<*next(it)<<endl;
        it++;
    }

    return 0;
}

