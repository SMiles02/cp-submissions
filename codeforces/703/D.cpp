#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

struct BIT {
    int n, rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1,0) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] ^= d; }
    int query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn ^= bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) ^ query(x - 1); }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, l, r, id;
    cin >> n;
    int a[n + 1], p[n + 1];
    p[0] = 0;
    map<int, int> last;
    BIT bit(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] ^ a[i];
    }
    cin >> q;
    int ans[q];
    vector<vector<array<int, 3>>> queries(n + 1);
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        queries[r].push_back({l, i});
    }
    for (int i = 1; i <= n; ++i) {
        if (last[a[i]])
            bit.update(last[a[i]], a[i]);
        last[a[i]] = i;
        for (auto j : queries[i])
            ans[j[1]] = bit.query(j[0], i);
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << "\n";
    return 0;
}