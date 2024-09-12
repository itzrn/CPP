#ifndef DARKNERD
#define DARKNERD

/*
  Compete against Yourself.
  DarkNerd
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define ld long double
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
//             (variable, start, end)
#define rep_inc(i, a, b) for (int i=a; i<b; i++)
#define rep_dec(i, a, b) for (int i=a; i>= b; i--)
#define rep_inc_step(i, a, b, step) for (int i=a; i<b; i+=step)
#define rep_dec_step(i, a, b, step) for (int i=a; i>=b; i-=step)
#define for_eachr(element, container) for (auto& element : container)
#define for_eachv(element, container) for (auto element : container)
// data structure
#define pii pair<int, int>
#define pib pair<int, bool>
#define pll pair<ll, ll>

#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define vl vector<ll>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>

#define stki stack<int>
#define stkl stack<long long>
#define stks stack<string>
#define stkc stack<char>

#define quei queue<int>
#define quel queue<long long>
#define ques queue<string>
#define quec queue<char>

#define uosi unordered_set<int>
#define uosl unordered_set<ll>
#define uosc unordered_set<char>
#define uoss unordered_set<string>

#define osi set<int>
#define osl set<ll>
#define oss set<string>

#define ms multiset
#define msi multiset<int>
#define msl multiset<ll>
#define msc multiset<char>
#define mss multiset<string>

#define uom unordered_map
#define uomivi unordered_map<int, vector<int>>
#define uomii unordered_map<int, int>
#define uomci unordered_map<char, int>
#define uomll unordered_map<ll, ll>

#define om map
#define omii map<int, int>
#define omll map<ll, ll>

#define mmii multimap<int, int>
#define mmll multimap<ll, ll>

// some functions
#define bitcountl(x) (__builtin_popcountll(x)) // used to count the number of set bit in the given long long value
#define bitcounti(x) (__builtin_popcount(x)) // used to count the number of set bit in the given int value
// #define bitcounti(x) (bitset<32>(x).count()) // used to count the number of set bit in the given int value
#define outl(x) (cout<<x<<endl) // this is used to print anyting to console
#define outln (cout<<endl)
#define out(x) (cout<<x<<" ")
#define biti(x) ({ int _count = 0; while(x > 0) { x >>= 1; _count++; } _count; })
#define bitl(x) ({ int _count = 0; while(x > 0) { x >>= 1; _count++; } _count; })

// ------------------------------------------------------------------------------------------ //
class BIT{ // this is only used for prefix sum
private:
    int n;
    int* bit;
    vector<int> arr;
public:
    BIT(vector<int>& arr):n(arr.size()), arr(arr){
        bit=new int[n+1];
        fill(bit, bit+n+1, 0);
        for(int i=0; i<n; i++){
            addval(i+1, arr[i]);
        }
    }
    ~BIT(){
        delete[] bit;
    }
    void addval(int i, int val){
        while(i<=n){
            bit[i] += val;
            i += i&(-i);
        }
    }
    // so let assume arr to be the original arr which conains all the original value
    // and if any index get updated like->
    // arr[4] = 6; was this
    // arr[4] = 2; current
    // the update function parameter wants -> 2-6 = -4 (current-previous)
    void update(int i, int add){ // this is like when you are updating any valye to another value
        int x = add-arr[i];
        arr[i]=add;
        i+=1;
        addval(i, x);
    }
    ll range_sum(int i, int j){ // i and j should be 0-based indexing (i->exclude, j->include)
        // where j>i
        return sum(j)-sum(i);
    }
    ll sum(int i){ // logn -> time
        i+=1; // updating to 1-based indexing
        int sum_=0;
        while(i>0){
            sum_ += bit[i];
            i-=(i&(-i)); // removing last bit
        }
        return sum_;
    }
};
class DSU{
    int n;
    int* parent;
    int* rank;
    int* size;
    int components;
    public:
        // int* compsum;
        DSU(int n):n(n), components(n){
            parent = new int[n];
            rank = new int[n];
            size = new int[n];
            // compsum = new int[n];
            for(int i=0; i<n; i++){
                rank[i]=1;
                size[i]=1;
                parent[i]=i;
            }
            // fill(rank, rank+n, 1);
            // fill(size, size+n, 1);
            // iota(parent, parent+n, 0);
        }
        ~DSU(){
            delete[]parent; 
            delete[] rank;
            delete[] size;
            // delete[] compsum;
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
                // compsum[yp] += compsum[xp];
            }else if(rank[yp]<rank[xp]){
                parent[yp]=xp;
                // compsum[xp]+=compsum[yp];
            }else{
                parent[xp] = yp;
                rank[yp]++;
                // compsum[yp] += compsum[xp];
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
        void union_(int x, int y){
            int xp = find_(x);
            int yp = find_(y);
            if(xp==yp){
                return;
            }
            parent[xp]=yp;
            components--;
        }
};
class SGT{
    /**
     * 1. Its a kind of binary tree
     * 2. 2 childrens of all non-leaf nodes
     * 3. leaf node represents a single node of the array
     * 4. other nodes represent an interval or range of an array
     * 5. height = log[n base 2]
     * 6. its a balanced binary tree
     * 7. to represent the segment tree we need total number of nodes:
     *                  2n -> give n is the size of array and n is of power of 2
     *                  2n-1 -> when n is not the power of 2
     * space -> 2n
     * time in building a segement tree -> n
     * time in updation is logn
     * time to find the sum between any range -> logn
     * to be on safe side we have take array size as 4n, when the n is not in power of 2 then we make 2*n leaf nodes, which mwkes the segment tree of size 2*2*n=4n
     */
    private:
        void buildSGT(int root, int left, int right){
            if(left == right){
                sgtree[root] == vec[left];
                return;
            }
            int mid = left+((right-left)>>1);
            buildSGT(2*root+1, left, mid);
            buildSGT(2*root+2, mid+1, right);
            sgtree[root] = sgtree[2*root+1]+sgtree[2*root+2];
        }
        int query(int start, int end, int root, int left, int right){
            if(left>end || right<start){ // out of bound hai according to start and end
                return 0;
            }
            if(start<=left && end>=right){
                return sgtree[root];
            }
            int mid = left+((right-left)>>1);
            return query(start, end, 2*root+1, left, mid)+query(start, end, 2*root+2, mid+1, right);
        }
        void point_update(int idx, int val, int root, int left, int right){
            if(left==right){
                sgtree[root]=val; // do sgtree[root]=vec[left]=val, if you want to permanently update the value
                return;
            }
            int mid=left+((right-left)>>1);
            if(idx<=mid){
                point_update(idx, val, 2*root+1, left, mid);
            }else{
                point_update(idx, val, 2*root+2, mid+1, right);
            }
            sgtree[root] = sgtree[2*root+1]+sgtree[2*root+2];
        }

        // this usese the concept of lazy prpogation
        void range_update(int start, int end, int val, int root, int left, int right){ // time-> logn
            if(lazytree[root] != 0){
                sgtree[root] += (right-left+1)*lazytree[root];
                if(left != right){ // means the root is not leaf node
                    lazytree[2*root+1]=lazytree[root];
                    lazytree[2*root+2]=lazytree[root];
                }
                lazytree[root]=0;
            }

            if(left>end || right<start){
                return;
            }
            if(start<=left && end>=right){
                sgtree[root] = (right-left+1)*val;
                if(left != right){
                    lazytree[2*root+1]+=val;
                    lazytree[2*root+2]+=val;
                }
                return;
            }

            int mid = left + ((right-left)>>1);
            range_update(start, end, val, 2*root+1, left, mid);
            range_update(start, end, val, 2*root+2, mid+1, right);
            sgtree[root] = sgtree[2*root+1]+sgtree[2*root+2];
        }
    public:
        vi sgtree;
        vi vec;
        int n;
        vi lazytree;
        SGT(vi& vec):vec(vec), n(vec.size()){
            sgtree=vi(4*n);
            lazytree=vi(4*n, 0);
            buildSGT(0, 0, n-1);
        }
        int query(int start, int end){
            return query(start, end, 0, 0, n-1);
        }
        void point_update(int idx, int val){
            point_update(idx, val, 0, 0, n-1);
        }
        void range_update(int start, int end, int val){
            range_update(start, end, val, 0, 0, n-1);
        }
};
class RMNQ{ // Range Minimum Query
    void buildRMNQ(int root, int left, int right){
        if(left==right){
            rmnq[root]=vec[left];
            return;
        }
        int mid = left+((right-left)>>1);
        buildRMNQ(2*root+1, left, mid);
        buildRMNQ(2*root+2, mid+1, right);
        rmnq[root] = min(rmnq[2*root+1], rmnq[2*root+2]);
    }
    int query(int start, int end, int root, int left, int right){
        if(left>end || right<start){
            return INT_MAX;
        }
        if(left>=start && right<=end){
            return rmnq[root];
        }
        int mid = left+((right-left)>>1);
        return min(query(start, end, 2*root+1, left, mid), query(start, end, 2*root+2, mid+1, right));
    }
public:
    int n;
    int* rmnq;
    vi vec;
    RMNQ(vi& vec):vec(vec), n(vec.size()){
        rmnq = new int[4*n];
        buildRMNQ(0, 0, n-1);
    }
    ~RMNQ(){
        delete[] rmnq;
    }
    int query(int start, int end){
        return query(start, end, 0, 0, n-1);
    }
};
class RMXQ{ // Range Maximum Query
    void buildRMXQ(int root, int left, int right){
        if(left==right){
            rmxq[root]=vec[left];
            return;
        }
        int mid = left+((right-left)>>1);
        buildRMXQ(2*root+1, left, mid);
        buildRMXQ(2*root+2, mid+1, right);
        rmxq[root] = max(rmxq[2*root+1], rmxq[2*root+2]);
    }
    int query(int start, int end, int root, int left, int right){
        if(left>end || right<start){
            return INT_MIN;
        }
        if(left>=start && right<=end){
            return rmxq[root];
        }
        int mid = left+((right-left)>>1);
        return max(query(start, end, 2*root+1, left, mid), query(start, end, 2*root+2, mid+1, right));
    }
public:
    int n;
    int* rmxq;
    vi vec;
    RMXQ(vi& vec):vec(vec), n(vec.size()){
        rmxq = new int[4*n];
        buildRMXQ(0, 0, n-1);
    }
    ~RMXQ(){
        delete[] rmxq;
    }
    int query(int start, int end){
        return query(start, end, 0, 0, n-1);
    }
};
// template <class T>
class DarkNerd {
    private:
        ll mod=1e9+7;
        bool isPrime(ll n) {
            if (n < 2){
                return false;
            }
            if (n == 2 || n == 3){
                return true;
            }
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
        // void meet_in_the_middle(int arr[], int st, int en, uomii& mp, int sm, int x){
        //     if(sm>x){
        //         return;
        //     }
        //     if(st>en || sm == x){
        //         mp[sm]++;
        //         return;
        //     }
        //     meet_in_the_middle(arr, st+1, en, mp, sm, x); // leave
        //     if(sm+arr[st] <= x){ // take
        //         meet_in_the_middle(arr, st+1, en, mp, sm+arr[st], x);
        //     }
        // }
    
    
    public:
        void solve(int tc) {
            
        }

}darknerd;
int main() {
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tt = 1;
    cin >> tt;
    int a=1;
    while(a<=tt){
        darknerd.solve(a);
        a++;
    }
    return 0;
}
#endif
/*
1.
    a function which is use to find the iterator with max element
    auto max_it = std::max_element(v.begin(), v.end(), [](int a, int b) {
        return std::abs(a) < std::abs(b);
    });

    to find the max element -> *max_it(this is the way to dereference the iterator to extract the value of it)

2.
    x&(-x); ye ek asa number dega jisme srif right most bit of x hoga

    x-(x&(-x)); ye ek asa number dega jisme se right most bit hat jyega



    void swapp(Node*& a, Node*& b){
        Node* temp = a;
        a=b;
        b=temp;
    }  

3. 
    std::string::const_iterator: This is the explicit type for a constant iterator over a std::string. 
    It ensures that the string cannot be modified through the iterator.

4.
    iterating a char* str; pointer

    void printString(const char *str) { // char* str = &s[0]; where s is string, and giving starting address to pointer str
        while (*str != '\0') {
            printf("%c", *str);
            str++; // Move to the next character
        }
        printf("\n");
    }

5.
    char* stra = &s[0];
    char str[] = stra; 


*/