#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long

//                 (variable, start, end)
#define rep_inc(i, a, b) for (int i=a; i<b; i++)
#define rep_dec(i, a, b) for (int i=a; i>= b; i--)
#define rep_step(i, a, b, step) for (int i=a; i<=b; i+=step)
// ------------------------------------------------------------------------------------------ //



template <class T>
class Contest {
    private:
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
            X %= M; 
            while (Y > 0) { 
                if (Y % 2) {
                    R = (R * X) % M; 
                } 
                X = (X * X) % M, Y /= 2; 
            } 
            return R; 
        }


    public:
        void solve() {

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