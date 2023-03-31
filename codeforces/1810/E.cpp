#include <bits/stdc++.h>
using namespace std;

queue<int> q;

struct DSU {
    vector<int> pt, sz;
    vector<set<array<int, 2>>> s;
    DSU(int n) : pt(n + 1), sz(n + 1), s(n + 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            pt[j] = i;
            sz[i] += sz[j];
            while (!s[j].empty()) {
                s[i].insert(*(s[j].begin()));
                s[j].erase(s[j].begin());
            }
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
    void check(int x) {
        x = find_set(x);
        while (!s[x].empty()) {
            int y = (*s[x].begin())[1], c = (*s[x].begin())[0];
            // cerr << y << " " << c << " " << sz[x] << "\n";
            if (find_set(x) == find_set(y)) {
                s[x].erase(s[x].begin());
                continue;
            }
            if (sz[find_set(y)] > 0)
                unite(x, y);
            else if (sz[x] >= c) {
                sz[y] = 1;
                unite(x, y);
                q.push(y);
            }
            else
                break;
            x = find_set(x);
        }
    }
};

const int N = 2e5 + 1;
int a[N];
vector<int> e[N];

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        e[i].clear();
        if (a[i] == 0) {
            q.push(i);
            dsu.sz[i] = 1;
        }
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        // cerr << x << "\n";
        for (auto y : e[x])
            if (dsu.find_set(x) != dsu.find_set(y)) {
                if (dsu.sz[dsu.find_set(y)] > 0)
                    dsu.unite(x, y);
                else if (dsu.sz[dsu.find_set(x)] >= a[y]) {
                    dsu.sz[y] = 1;
                    dsu.unite(x, y);
                    q.push(y);
                }
                else
                    dsu.s[dsu.find_set(x)].insert({a[y], y});
            }
        dsu.check(x);
    }
    if (dsu.sz[dsu.find_set(1)] == n)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}