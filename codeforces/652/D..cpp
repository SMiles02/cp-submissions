#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

template<class T> struct implicit_segtree {
    // merge(ID, x) = x
    // range [0, n]
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
    implicit_segtree(int n) : n(n) {root = newnode();}
    void update(node *&v, int l, int r, int i, T x) {
        if (i < l || r < i)
            return;
        // cerr << l << " " << i << " " << r << endl;
        if (!v) 
            v = newnode();
        v->val = merge(v->val, x);
        if (l==r)
            return;
        update(v->l, l, l + (r - l) / 2, i, x);
        update(v->r, l + (r - l) / 2 + 1, r, i, x);
    }
    void update(int i, T x) {
        update(root, 0, n, i, x);
    }
    T query(node* v, int cL, int cR, int l, int r) {
        if (r < cL || cR < l || !v)
            return ID;
        if (l <= cL && cR <= r)
            return v->val;
        return merge(query(v->l, cL, cL + (cR - cL) / 2, l, r), query(v->r, cL + (cR - cL) / 2 + 1, cR, l, r));
    }
    T query(int l, int r) {
        return query(root, 0, n, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    vector<int> ans(n);
    implicit_segtree<int> seg((int)2e9);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        ans[a[i][2]] = seg.query(a[i][1] + 1e9, a[i][0] + 1e9);
        seg.update(a[i][1] + 1e9, 1);
    }
    for (int i : ans) {
        cout << i << "\n";
    }
    return 0;
}