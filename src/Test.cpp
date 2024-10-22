#include <iostream>
#include <cmath>
#include <array>
#include <vector>
using namespace std;

#define ll long long

class SegmentTree{
    void buildTree(int root, int lft, int rgt){
        if(lft == rgt){
            sgt[lft] = vec[lft];
            return;
        }
        int mid = lft+((rgt-lft)>>1);
        buildTree(2*root+1, lft, mid);
        buildTree(2*root+2, mid+1, rgt);
        sgt[root] =sgt[2*root+1]+sgt[2*root+2];
    }

    void update_point(int root, int lft, int rgt, int idx, int val){
        if(lft==rgt){
            sgt[root]=val;
            return;
        }
        int mid = lft+((rgt-lft)>>1);
        if(idx<=mid){
            update_point(2*root+1, lft, mid, idx, val);
        }else{
            update_point(2*root+2, mid+1, rgt, idx, val);
        }
        sgt[root] = sgt[2*root+1]+sgt[2*root+2];
    }

    int query(int root, int lft, int rgt, int i, int j){
        if(i>rgt || j<lft){
            return 0;
        }
        if(lft>=i && rgt<=j){
            return sgt[root];
        }
        int mid = lft+((rgt-lft)>>1);
        return query(2*root+1, lft, mid, i, j) + query(2*root+2, mid+1, rgt, i, j);
    }

    void range_update(int root, int lft, int rgt, int val, int i, int j){
        if(lazy[root] != 0){
            sgt[root] += (rgt-lft+1)*lazy[root];
            if(lft!=rgt){
                lazy[2*root+1] += lazy[root];
                lazy[2*root+2] += lazy[root];
            }
            lazy[root]=0;
        }

        if(i>rgt || j<lft || lft>rgt){
            return;
        }

        if(lft>=i && rgt<=j){
            sgt[root] += (rgt-lft+1)*val;
            if(lft!=rgt){
                lazy[2*root+1] += val;
                lazy[2*root+2] += val;
            }
            return;
        }

        int mid = lft+((rgt-lft)>>1);
        range_update(2*root+1, lft, mid, val, i, j);
        range_update(2*root+2, mid+1, rgt, val, i, j);
    }
public:
    int n;
    vector<int> sgt, vec, lazy;
    SegmentTree(int n, vector<int>& vec):n(n), vec(vec), sgt(vector<int>(4*n, 0)), lazy(vector<int>(4*n, 0)){}
};

int main(){
    return 0;
}


class Lazy {
    vector<ll> seg;
    vector<ll> lazy;

  public:
    // segment tree constructor for defining the size
    Lazy(ll n) {
        seg.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
    }

    // operation function
    ll comp(ll a, ll b) { return a + b; }

    // to propagate the lazy value
    void propagate(ll node, ll val, ll start, ll end) {
        seg[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[2 * node + 1] += val;
            lazy[2 * node + 2] += val;
        }
    }

    // for building the segment tree
    void build(ll ind, ll left, ll right, vector<ll>& arr) {
        if (left > right)
            return;
        // when on the leaf node, add the value to the segment
        if (left == right) {
            seg[ind] = arr[left];
            return;
        }
        // now go on the build the left and right subtree
        ll mid = left + (right - left) / 2;
        // left subtree
        build(2 * ind + 1, left, mid, arr);
        // right subtree
        build(2 * ind + 2, mid + 1, right, arr);
        // operation which you need to perform on the subtree
        seg[ind] = comp(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    // for the query of the data
    ll query(ll ind, ll left, ll right, ll l, ll r) {
        // when the segment is not in the range (disjoll)
        if (r < left || l > right)
            return 0;
        // propagate the lazy value
        if (lazy[ind] != 0) {
            propagate(ind, lazy[ind], left, right);
            lazy[ind] = 0;
        }
        // when fully in the range
        if (l <= left && right <= r) {
            return seg[ind];
        }
        // partial overlapping
        ll mid = left + (right - left) / 2;
        ll leftC = query(2 * ind + 1, left, mid, l, r);
        ll rightC = query(2 * ind + 2, mid + 1, right, l, r);
        // operation which you need to perform on the subtree
        return comp(leftC, rightC);
    }

    // range update for the tree
    void update(ll ind, ll left, ll right, ll l, ll r, ll val) {
        // propagate the value
        if (lazy[ind] != 0) {
            propagate(ind, lazy[ind], left, right);
            lazy[ind] = 0;
        }
        // outside range
        if (left > r || right < l || left > right)
            return;
        // when on the leaf node, update the value
        if (left >= l && right <= r) {
            propagate(ind, val, left, right);
            return;
        }
        // now check on the left and right
        ll mid = left + (right - left) / 2;
        // update the left and right child
        update(2 * ind + 1, left, mid, l, r, val);
        update(2 * ind + 2, mid + 1, right, l, r, val);
        // operation which you need to perform on the tree
        seg[ind] = comp(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

class Solution {
  public:
    vector<ll> zigzagQueries(int n, vector<int>& arr, int q,
                             vector<vector<int>>& queries) {
        vector<ll> fst, snd;
        for (ll i = 0; i < n; i++) {
            if (i & 1)
                snd.push_back(arr[i]);
            else
                fst.push_back(arr[i]);
        }
        Lazy fstLazy(fst.size()), sndLazy(snd.size());
        fstLazy.build(0, 0, fst.size() - 1, fst);
        sndLazy.build(0, 0, snd.size() - 1, snd);
        vector<ll> ans;
        for (ll i = 0; i < q; i++) {
            ll t = queries[i][0];
            ll l = queries[i][1];
            ll r = queries[i][2];
            if (t == 1) {
                ll x = queries[i][3];
                if (l & 1) {
                    ll l1 = l + 1, r1 = -1;
                    ll l2 = l, r2 = -1;
                    if (r & 1) {
                        r1 = r - 1;
                        r2 = r;
                    } else {
                        r1 = r;
                        r2 = r - 1;
                    }
                    if (l1 <= r1)
                        fstLazy.update(0, 0, fst.size() - 1, (l + 1) / 2, r / 2, -x);
                    if (l2 <= r2)
                        sndLazy.update(0, 0, snd.size() - 1, l / 2, (r - 1) / 2, x);
                } else {
                    ll l1 = l, r1 = -1;
                    ll l2 = l + 1, r2 = -1;
                    if (r & 1) {
                        r1 = r - 1;
                        r2 = r;
                    } else {
                        r1 = r;
                        r2 = r - 1;
                    }
                    if (l1 <= r1)
                        fstLazy.update(0, 0, fst.size() - 1, l / 2, r / 2, x);
                    if (l2 <= r2)
                        sndLazy.update(0, 0, snd.size() - 1, l / 2, (r - 1) / 2, -x);
                }
            } else {
                if (l & 1) {
                    ll l1 = l + 1, r1 = -1;
                    ll l2 = l, r2 = -1;
                    if (r & 1) {
                        r1 = r - 1;
                        r2 = r;
                    } else {
                        r1 = r;
                        r2 = r - 1;
                    }
                    ll v1 = 0, v2 = 0;
                    if (l2 <= r2)
                        v1 = sndLazy.query(0, 0, snd.size() - 1, l / 2, (r - 1) / 2);
                    if (l1 <= r1)
                        v2 = fstLazy.query(0, 0, fst.size() - 1, (l + 1) / 2, r / 2);
                    ans.push_back(v1 - v2);
                } else {
                    ll l1 = l, r1 = -1;
                    ll l2 = l + 1, r2 = -1;
                    if (r & 1) {
                        r1 = r - 1;
                        r2 = r;
                    } else {
                        r1 = r;
                        r2 = r - 1;
                    }
                    ll v1 = 0, v2 = 0;
                    if (l1 <= r1)
                        v1 = fstLazy.query(0, 0, fst.size() - 1, l / 2, r / 2);
                    if (l2 <= r2)
                        v2 = sndLazy.query(0, 0, snd.size() - 1, l / 2, (r - 1) / 2);
                    ans.push_back(v1 - v2);
                }
            }
        }
        return ans;
    }
};



#define ll long long
class SegmentTree {
private:
    void buildTree(ll root, ll lft, ll rgt) {
        if(lft>rgt){
            return;
        }
        if (lft == rgt) {
            sgt[root] = vec[lft];
            return;
        }
        ll mid = lft + ((rgt - lft) >> 1);
        buildTree(2 * root + 1, lft, mid);
        buildTree(2 * root + 2, mid + 1, rgt);
        sgt[root] = sgt[2 * root + 1] + sgt[2 * root + 2];
    }

    ll query(ll root, ll lft, ll rgt, ll i, ll j) {
        if (i > rgt || j < lft) {
            return 0;
        }
        if (lazy[root] != 0) {
            sgt[root] += (rgt - lft + 1) * lazy[root];
            if (lft != rgt) {
                lazy[2 * root + 1] += lazy[root];
                lazy[2 * root + 2] += lazy[root];
            }
            lazy[root] = 0;
        }
        if (i <= lft && rgt <= j) {
            // return sgt[root]+lazy[root]*(rgt-lft+1);
            return sgt[root];
        }
        ll mid = lft + ((rgt - lft) >> 1);
        return query(2 * root + 1, lft, mid, i, j) + query(2 * root + 2, mid + 1, rgt, i, j);
    }
    
    void update(ll root, ll lft, ll rgt, ll val, ll i, ll j) {
        if (lazy[root] != 0) {
            sgt[root] += (rgt - lft + 1) * lazy[root];
            if (lft != rgt) {
                lazy[2 * root + 1] += lazy[root];
                lazy[2 * root + 2] += lazy[root];
            }
            lazy[root] = 0;
        }
        if (i > rgt || j < lft || lft > rgt) {
            return;
        }
        if (i <= lft && rgt <= j) {
            sgt[root] += (rgt - lft + 1) * val;
            if (lft != rgt) {
                lazy[2 * root + 1] += val;
                lazy[2 * root + 2] += val;
            }
            return;
        }
        ll mid = lft + ((rgt - lft) >> 1);
        update(2 * root + 1, lft, mid, val, i, j);
        update(2 * root + 2, mid + 1, rgt, val, i, j);
        sgt[root] = sgt[2*root+1]+sgt[2*root+2];
    }

    ll n;
    vector<ll> vec, sgt, lazy;

public:
    SegmentTree(ll n, vector<ll>& vec) : n(n), vec(vec), sgt(4*n+1, 0), lazy(4*n+1, 0) {
        buildTree(0, 0, n - 1);
    }
    void update(ll val, ll i, ll j) {
        update(0, 0, n - 1, val, i, j);
    }
    ll query(ll i, ll j) {
        return query(0, 0, n - 1, i, j);
    }
};

class Solution {
public:
    vector<long long> zigzagQueries(int n, vector<int>& arr, int q, vector<vector<int>>& queries) {
        vector<ll> ans;
        vector<ll> even, odd;

        for (int i = 0; i < n; i++) {
            if (i & 1) {
                odd.push_back(arr[i]);
            } else {
                even.push_back(arr[i]);
            }
        }
        
        SegmentTree sgte(even.size(), even), sgto(odd.size(), odd);
        
        for (ll i = 0; i < q; i++) {
            ll t = queries[i][0];
            ll l = queries[i][1];
            ll r = queries[i][2];
            if (t == 1) {
                ll x = queries[i][3];
                if (l & 1) {
                    ll l1 = l + 1, r1 = -1;
                    ll l2 = l, r2 = -1;
                    if (r & 1) {
                        r1 = r - 1;
                        r2 = r;
                    } else {
                        r1 = r;
                        r2 = r - 1;
                    }
                    if (l1 <= r1)
                        sgte.update(-x, (l + 1) / 2, r / 2);
                    if (l2 <= r2)
                        sgto.update(x, l / 2, (r - 1) / 2);
                } else {
                    ll l1 = l, r1 = -1;
                    ll l2 = l + 1, r2 = -1;
                    if (r & 1) {
                        r1 = r - 1;
                        r2 = r;
                    } else {
                        r1 = r;
                        r2 = r - 1;
                    }
                    if (l1 <= r1)
                        sgte.update(x, l / 2, r / 2);
                    if (l2 <= r2)
                        sgto.update(-x, l / 2, (r - 1) / 2);
                }
            } else {
                if (l & 1) {
                    ll l1 = l + 1, r1 = -1;
                    ll l2 = l, r2 = -1;
                    if (r & 1) {
                        r1 = r - 1;
                        r2 = r;
                    } else {
                        r1 = r;
                        r2 = r - 1;
                    }
                    ll v1 = 0, v2 = 0;
                    if (l2 <= r2)
                        v1 = sgto.query(l / 2, (r - 1) / 2);
                    if (l1 <= r1)
                        v2 = sgte.query((l + 1) / 2, r / 2);
                    ans.push_back(v1 - v2);
                } else {
                    ll l1 = l, r1 = -1;
                    ll l2 = l + 1, r2 = -1;
                    if (r & 1) {
                        r1 = r - 1;
                        r2 = r;
                    } else {
                        r1 = r;
                        r2 = r - 1;
                    }
                    ll v1 = 0, v2 = 0;
                    if (l1 <= r1)
                        v1 = sgte.query(l / 2, r / 2);
                    if (l2 <= r2)
                        v2 = sgto.query(l / 2, (r - 1) / 2);
                    ans.push_back(v1 - v2);
                }
            }
        }

        return ans;
    }
};
