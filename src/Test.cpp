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
#include <string.h>
#include <algorithm>
#include <cctype>
// #define long long as ll
using namespace std;

// class Solution {
//     int dp[300][1000]={};
//     int recursion(string& s, int idx, int strlen, vector<string>& dict, int n){
//         if(idx==strlen){
//             return true;
//         }

//         for(int i=0; i<n; i++){
//             int temp =  dict[i].length();
//             if(s.substr(idx, temp) == dict[i] && recursion(s, idx+temp, strlen, dict, n)){
//                 return dp[idx][i]=true;
//             }
//         }

//         return false;
//     }
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int strlen = s.length();
//         int n=wordDict.size();

//         return recursion(s, 0, strlen, wordDict, n);
//     }
// };

// #include <iostream>

class Solution {
    bool check(int arr[], int k, int size=26){
        int max_=0;
        int count=0;
        for(int i=0; i<size; i++){
            if(arr[i] != 0){
                max_ = max(max_, arr[i]);
                count += arr[i];
            }
        }
        return count-max_<=k;
    }
public:
    int characterReplacement(string s, int k) {
        int arr[26]={};
        int n=s.length();
        int left = 0;
        int right=0;
        
        int max_=0;
        while(right<n){
            arr[s[right]-'A']++;
            while(!check(arr, k)){
                arr[s[left++]-'A']--;
            }

            max_=max(max_, right-left+1);
        }

        return max_;
    }
};

void printArray(int arr[], int size=26) {
    // int a = sizeof(arr);
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    
}
bool binarySearch(vector<int>& vec, long long k, int mid){
    if(mid == 0){
        return true;
    }

    int sum_=0;
    for(int i:vec){
        sum_ += i/mid;
    }

    return sum_>=k;
}

int abcd(int** arr){
    long long x=100000000000;
    return x;
}

int main() {
    // int n=12;
    // int ar[n] = {};
    // long a = 10000L;
    // ll b=100;
    // map<int, int> map_;
    // map_[2]++;
    // map<int, int> :: iterator it = map_.begin();
    // cout<<it->first<<endl;
    // vector<pair<int, pair<int, int>>> vec;
    // vec.push_back({1, {1,2}});

    // int visited[10];
    // // bool a = -1;
    // cout<<visited[1]<<endl;
    // map_.

    // int n,m;
    // cin>>n>>m;
    // char** arr = new char*[n]


    int yu = NULL;
    yu=10;

    cout<<yu<<endl;

    // string a="Aryan";
    // // cout<<string::max_size()<<endl;
    // unordered_set<int> set_;
    // unordered_set<int> :: iterator it = set_.begin();

    // cout<<abcd()<<endl;
    // int size = sizeof(ar) / sizeof(ar[0]);
    // printArray(ar, n);
    return 0;
}


// int maxOccured(int n, int l[], int r[], int maxx) {
//     int arr[1000001];
//     memset(arr, 0, sizeof(arr));
    
//     for(int i=0; i<n; i++){
//         arr[l[i]]++;
//         arr[r[i+1]]--;
//     }
    
//     for(int i=1; i<= 1000000; i++){
//         arr[i] += arr[i-1];
//     }
    
//     int max_=0;
//     for(int i=1; i<=1000000; i++){
//         if(arr[i]>arr[max_]){
//             max_=i;
//         }
//     }
    
//     return max_;
// }


// int main() {
    // bool arr[2][4]={};
    // if(!arr[1][1]){
    //     cout<<"Aryan"<<endl;
    // }
    // // cout<<arr[1][1]<<endl;
    // int dirx[4] = {1, -1, 0, 0};
    // cout<<dirx[0]<<endl;
    // queue<vector<int>> q;
    // q.push({1, 2});
    // vector<int> temp = q.front();
    // q.pop();
    // cout<<temp[0]<<endl;

    // auto cmp = [](const int& a, const int&b){
    //     return a<b;
    // };
    // map<int, int, decltype(cmp)> map_(cmp); 
    // map_[0]++;
    // map_[1]++;
    // cout<<map_[3]<<endl;

    // map_.erase(it+3);
    // map<int, int> :: iterator it = map_.begin();
    // for (auto it = map_.begin(); it != prev(map_.end()); it++)
    // {
    //     /* code */
    // }

    // string st = "Aryan";
    // const char *ar = st.c_str();// only to read
    // st[0]='I';
    // cout<<st<<endl;

    // queue<int> q;
    // bool arr[10][12] = {};
    // if(!arr[0][0]){
    //     cout<<"Aryan ki jai ho"<<endl;
    // }

    // auto cmp = [](const vector<int>& a, const vector<int>& b){
    //     return a[0]>b[0];
    // };
    // vector<vector<int>> a;
    // a.push_back({1, 9});
    // a.push_back({1, 9});
    // a.push_back({1, 9});
    // a.push_back({1, 9});
    // a.push_back({1, 9});
    // priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq (cmp, a);

    // // priority_queue<vector<int>, vector<vector<int>>> :: iterator i;
    
    // cout<<pq.top()[0]<<endl;

    // string l="0ok r";
    // if(!isalpha(l[0])){
    //     cout<<"Aryan"<<endl;
    // }

    // stack<char> s;
    // char t=s.top();

    // string str="";
    // str += 71;
    // cout<<str<<endl;

    // deque<int> deque_;
    // deque_.

    // queue<int> q;
    // while(1){

    // }

    // cout<<(-4)%2<<endl;
    // unordered_map<int, int> map_;
    // cout<<map_[8]<<endl;

    // unordered_set<int> set_;
    // // unordered_set<int> :: iterator it;

    // auto it = set_.insert(7);

    // map<int, int> map_;
    // if(map_[89] == 0){
    //     cout<<"Aryan"<<endl;
    // }

    // map<int, int> :: iterator it = map_.begin();
    // while(it != map_.end()){
    //     it++;
    // }

    // set<int> set_;
    

    // map_[0]++;
    // map_[1]++;
    // map_[1]++;
    // map_[0]--;
    // map_[1]--;
    // map_[1]--;
    // cout<<map_.empty()<<endl;
    // int a=1^2;
    // cout<<a<<endl;
    
    

    // string s = "Aryan";
    // int strlen = s.length();
    // bool dp[strlen+1]={};
    
    // cout<<st.substr(0, 7)<<endl;
//     return 0;
// }