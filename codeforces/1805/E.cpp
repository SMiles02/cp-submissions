#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int n, a[N], b[N * 2], tin[N], tout[N], t = 1, ans[N];
vector<int> e[N];

template<class T> struct PST {
    // merge(ID,x) = x
    // range [0,n]
    T merge(T a, T b) { return max(a, b); }
    struct node {
        T val;
        node *l, *r;
        node(T x) : val(x) {}
    };
    deque<node> buffer;
    node *newnode(T x = 0) {
        buffer.emplace_back(x);
        return &buffer.back();
    }
    node *newnode(node *l, node *r) {
        auto x = newnode(merge(l->val,r->val));
        x->l = l, x->r = r;
        return x;
    }
    int n, a = 0;
    node *roots[N * 2]; //change this to how many tree copies there can be
    PST(int n) : n(n) {roots[0] = build(0, n);}
    node *build(int l, int r) {
        if(l == r) 
            return newnode(0);
        return newnode(build(l,(l+r)>>1),build((l+r+2)>>1, r));
    }
    node *update(node *v, int l, int r, int i, T x) {
        if(r < i || i < l)
            return v;
        if(l == r)
            return newnode(x);
        return newnode(update(v->l,l,(l+r)>>1,i,x), update(v->r,(l+r+2)>>1,r,i,x));
    }
    void update(int k, int i, T x) { roots[k] = update(roots[k], 0, n, i, x); }
    T query(node *v, int cL, int cR, int l, int r) {
        if (r<cL||cR<l)
            return 0;
        if (l<=cL&&cR<=r)
            return v->val;
        return merge(query(v->l,cL,(cL+cR)>>1,l,r), query(v->r,(cL+cR+2)>>1,cR,l,r));
    }
    T query(int k, int l, int r) { return query(roots[k],0,n,l,r); }
    T query(int l, int r) { return query(roots[r], 0, n, l, r); }
    void clone(int k) {
        roots[++a] = newnode(roots[k]->l, roots[k]->r);
        roots[a]->val = roots[k]->val;
    }
};

void dfs(int c, int p) {
    // cerr << "entered " << c << "\n";
    tin[c] = t++;
    b[tin[c]] = b[tin[c] + n] = a[c];
    // cerr << tin[c] << " " << tin[c] + n << "!\n";
    for (int i : e[c])
        if (i != p)
            dfs(i, c);
    tout[c] = t - 1;
    // cerr << c << ": " << tin[c] << " " << tout[c] << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y, cur = 0;
    cin >> n;
    vector<array<int, 2>> ed;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        ed.push_back({x, y});
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dfs(1, 0);
    PST<int> pst(n * 2);
    map<int, int> m;
    for (int i = 1; i <= n * 2; ++i) {
        // cerr << b[i] << " ";
        pst.clone(i - 1);
        if (m[b[i]])
            pst.update(i, m[b[i]], b[i]);
        m[b[i]] = i;
    }
    // cerr << "\n";
    for (auto i : ed) {
        if (tin[i[1]] > tin[i[0]])
            swap(i[0], i[1]);
        cout << max(pst.query(tin[i[0]], tout[i[0]]), pst.query(tout[i[0]] + 1, tin[i[0]] + n - 1)) << "\n";
    }

    // cout << "done\n";
    return 0;
}