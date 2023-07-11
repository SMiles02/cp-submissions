#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    vector<int> p, sz;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int i) {
        return i == p[i] ? i : p[i] = find_set(p[i]);
    }
    void unite(int i, int j) {
        // cout << i << " " << j << "\n";
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            p[j] = i;
            sz[i] += sz[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    disjoint_set_union rows(max(n, m) * 2), cols(max(n, m) * 2);
    vector<array<int, 3>> joins(k);
    for (int i = 0; i < k; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        joins[i] = {min(a, c), min(b, d), (b + 1) == d};
        // cout << joins[i][0] << " " << joins[i][1] << " " << joins[i][2] << " !\n";
        for (int j = 0; j < i; ++j) {
            if (joins[i][0] == joins[j][0]) {
                int x = joins[i][1], y = joins[j][1];
                // cout << x << " " << y << " !!\n";
                if (joins[i][2] == joins[j][2]) {
                    rows.unite(x, y);
                    rows.unite(x + max(n, m), y + max(n, m));
                }
                else {
                    rows.unite(x, y + max(n, m));
                    rows.unite(x + max(n, m), y);
                }
            }
            if (joins[i][1] == joins[j][1]) {
                int x = joins[i][0], y = joins[j][0];
                if (joins[i][2] == joins[j][2]) {
                    // cout << "1:\n";
                    cols.unite(x, y);
                    cols.unite(x + max(n, m), y + max(n, m));
                }
                else {
                    // cout << "2:\n";
                    cols.unite(x, y + max(n, m));
                    cols.unite(x + max(n, m), y);
                }
            }
        }
    }
    for (int i = 1; i <= max(n, m); ++i) {
        if (rows.connected(i, i + max(n, m)) || cols.connected(i, i + max(n, m))) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}