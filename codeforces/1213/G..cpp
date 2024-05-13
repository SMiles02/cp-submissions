#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct disjoint_set_union {
    ll ans = 0;
    vector<int> p, sz;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int i) {
        return i == p[i] ? i : p[i] = find_set(p[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            p[j] = i;
            ans += 1LL * sz[i] * sz[j];
            sz[i] += sz[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, p = 0;
    cin >> n >> m;
    vector<array<int, 3>> e(n - 1);
    disjoint_set_union dsu(n);
    for (auto &[w, u, v] : e) {
        cin >> u >> v >> w;
    }
    sort(e.begin(), e.end());
    vector<array<int, 2>> q(m);
    vector<ll> ans(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i][0];
        q[i][1] = i;
    }
    sort(q.begin(), q.end());
    for (auto [w, i] : q) {
        while (p < n - 1 && e[p][0] <= w) {
            dsu.unite(e[p][1], e[p][2]);
            ++p;
        }
        ans[i] = dsu.ans;
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}