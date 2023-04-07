#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] ^= d; }
    int query(int x) {
        int rtn = 0;
        for (int i = x; i; i -= i & -i) rtn ^= bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) ^ query(x - 1); }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> last;
    BIT bit(n);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> q;
    vector<int> ans(q);
    vector<vector<array<int, 3>>> queries(n + 1);
    for (int i = 0; i < q; ++i) {
        int l, r;
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
    for (auto i : ans)
        cout << i << "\n";
    return 0;
}