#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<vector<int>>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid][0] == target) {
            return arr[mid][1];
        } else if (arr[mid][0] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}


pair<int, int> solve(){
    stack<int> st;
    
    return make_pair(1, 2);
}

int main() {
    int n, target;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0];
        arr[i][1] = i;
    }
    cin >> target;
    
    sort(begin(arr), end(arr), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    
    for (int i = 0; i < n - 1; i++) {
        int a = binarySearch(arr, target - arr[i][0], i + 1, n - 1);
        if (a != -1) {
            if (i < a) {
                cout << i << " " << a << endl;
            } else {
                cout << a << " " << i << endl;
            }
            return 0;
        }
    }
    
    return 0;
}