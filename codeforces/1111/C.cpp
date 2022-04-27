// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

template<class T> struct Implicit {
    // merge(ID,x) = x
    // range [0,n]
    const T ID = 0;
    T merge(T a, T b) { return a + b; }
    struct node {
        T val = 0;
        node *l, *r;
    };
    deque<node> buffer;
    node *newnode() {
        buffer.emplace_back();
        return &buffer.back();
    }
    int n;
    node *root;
    Implicit(int n) : n(n) {root = newnode();}
    void update(node *&v, int l, int r, int i, T x) {
        if (i<l||r<i)
            return;
        if (!v) 
            v=newnode();
        v->val = merge(v->val, x);
        if (l==r)
            return;
        update(v->l,l,(l+r)>>1,i,x);
        update(v->r,(l+r+2)>>1,r,i,x);
    }
    void update(int i, T x) {
        update(root, 0, n, i, x);
    }
    T query(node* v, int cL, int cR, int l, int r) {
        if (r<cL||cR<l||!v)
            return ID;
        if (l<=cL&&cR<=r)
            return v->val;
        return merge(query(v->l,cL,(cL+cR)>>1,l,r), query(v->r,(cL+cR+2)>>1,cR,l,r));
    }
    T query(int l, int r) {
        return query(root,0,n,l,r);
    }
};

Implicit<int> seg(1 << 30);
int n, k, A, B;

ll solve(int l, int r) {
    if (seg.query(l, r) == 0)
        return A;
    if (l == r)
        return 1LL * B * seg.query(l, r) * (r - l + 1);
    return min(1LL * B * seg.query(l, r) * (r - l + 1), solve(l, l + (r - l) / 2) + solve(l + (r - l) / 2 + 1, r));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> A >> B;
    int x;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        seg.update(x, 1);
    }
    cout << solve(1, 1 << n);
    return 0;
}