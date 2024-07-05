#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
//                 (variable, start, end)
#define rep_inc(i, a, b) for (int i=a; i<=b; i++)
#define rep_dec(i, a, b) for (int i=a; i>= b; i--)
#define rep_step(i, a, b, step) for (int i=a; i<=b; i+=step)
// ------------------------------------------------------------------------------------------ //


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
            delete[]parent, rank, size;
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

template <class T>
class Contest {
    private:
        ll mod=1e9+7;
        void input_Arr(T arr[], int n){
            for(int i=0; i<n; i++){
                cin>>arr[i];
            }
        }
        vector<T> input_vector(int n) {
            vector<T> vec;
            for (int i = 0; i < n; i++) {
                T num;
                cin >> num;
                vec.push_back(num);
            }
            return vec;
        }
        vector<vector<T>> input_2d_vector(int n, int m){
            vector<vector<T>> vec(n, vector<int> (m, 0));
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    T num;
                    cin>>num;
                    vec[i][j] = num;
                }
            }
            return vec;
        }
        // swap is already available in std namespace, so i need to change the name to swapp
        void swapp(T &a, T &b){
            T temp = a;
            a=b;
            b=temp;
        }

        bool isPrime(ll n) {
            if (n < 2)
                return false;
            if (n == 2 || n == 3)
                return true;
            if (n % 2 == 0 || n % 3 == 0)
                return false;
    
            for (ll i = 6; i*i <= n; i += 6) {
                if ((n % (i - 1) == 0) || (n % (i + 1) == 0)) {
                    return false;
                }
            }
            return true;
        }
        ll gcd(ll X, ll Y) { 
            return !Y ? X : gcd(Y, X % Y);
        }
        ll lcm(ll X, ll Y) { 
            return X * Y / gcd(X, Y); 
        }
        ll exppow(ll X, ll Y) { 
            ll R = 1; 
            X %= mod; 
            while (Y > 0) { 
                if (Y % 2) {
                    R = (R * X) % mod; 
                } 
                X = (X * X) % mod, Y /= 2; 
            } 
            return R; 
        }

    public:
        void solve() {
            
            // T n;
            // cin>>n;
            // T arr[n];

            

            // for(int i=0; i<n; i++){
            //     cin>>arr[i];
            // }

            // unordered_map<T, int> mp;
            // int mx=0;
            // T mx_ele=0;
            // for(int i=0; i<n; i++){
            //     mp[arr[i]]++;
            //     if(mx<mp[arr[i]]){
            //         mx = mp[arr[i]];
            //         mx_ele = arr[i];
            //     }
            // }

            // int ans = (n-mx)*mx_ele;
            // ans = min(ans, n*1);

            // cout<<ans<<endl;

            

        }

};
Contest<int> contestInt;
// Contest<char> contestChar;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t-- > 0) {
        contestInt.solve();
        // contestChar.solve();
    }
    return 0;
}


/*
1.
    a function which is use to find the iterator with max element
    auto max_it = std::max_element(v.begin(), v.end(), [](int a, int b) {
        return std::abs(a) < std::abs(b);
    });

    to find the max element -> *max_it(this is the way to dereference the iterator to extract the value of it)

2.



void swapp(Node*& a, Node*& b){
    Node* temp = a;
    a=b;
    b=temp;
}  
*/