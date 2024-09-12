#include <bits/stdc++.h>
using namespace std;

string trim(string);
bool isp2(int n){
    return (n&(n-1))==0;
}

int dfs(vector<int>& vec, int curr, int prev, vector<vector<int>>& dp){
    if(curr >= vec.size()){
        return 0;
    }
    if(dp[curr][prev+1] != -1){
        return dp[curr][prev+1];
    }
    int x=0;
    if(prev==-1 || vec[curr]==vec[prev] || (vec[curr]>vec[prev] && (vec[curr]-vec[prev]==1 || isp2(vec[curr]-vec[prev])))){
        x = 1+dfs(vec, curr+1, curr, dp);
    }
    int y=dfs(vec, curr+1, prev, dp);
    return dp[curr][prev+1] = max(x, y);
}

int getLIS(int N, vector<int> A) {
    vector<vector<int>> dp(N, vector<int>(N+1, -1));
    return dfs(A, 0, -1, dp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string inputline;

    getline(cin, inputline);
    int N = stoi(trim(inputline));
    
    vector<int> A(N);
    for(int j=0; j<N; j++) {
        getline(cin, inputline);
        A[j] = stoi(trim(inputline));
    }

    int result = getLIS(N, A);

    cout << result << "\n";

    return 0;
}


/* Utility functions. Don't modify these */
string trim(string str){
  if(str.empty())
      return str;

  size_t firstScan = str.find_first_not_of(' ');
  size_t first     = firstScan == string::npos ? str.length() : firstScan;
  size_t last      = str.find_last_not_of(' ');
  return str.substr(first, last-first+1);
}