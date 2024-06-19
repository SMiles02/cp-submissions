#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, x, y;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<array<int, 2>> v(n + 2), w(n + 2);
    set<array<int, 3>> a;
    set<array<int, 3>, greater<array<int, 3>>> b;
    x = 0;
    y = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') {
            ++y;
        }
        else if (s[i] == 'D') {
            --y;
        }
        else if (s[i] == 'L') {
            --x;
        }
        else {
            ++x;
        }
        v[i + 1] = {x, y};
        a.insert({x, y, i + 1});
    }
    x = 0;
    y = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'U') {
            ++y;
        }
        else if (s[i] == 'D') {
            --y;
        }
        else if (s[i] == 'L') {
            --x;
        }
        else {
            ++x;
        }
        w[i + 1] = {x, y};
        b.insert({x, y, i + 1});
    }
    // for (auto [x, y, i] : b) {
    //     cout << "{" << x << ", " << y  << ", " << i << "}\n";
    // }
    while (q--) {
        // cout << "new query\n";
        int l, r;
        cin >> x >> y >> l >> r;
        bool ok = (x == 0 && y == 0) || (x == v[n][0] && y == v[n][1]);
        if (a.upper_bound({x, y, -1}) != a.end()) {
            int i = (*a.upper_bound({x, y, -1}))[2];
            if (i < l && v[i][0] == x && v[i][1] == y) {
                // cout << "pos " << i << "\n";
                ok = true;
            }
        }
        if (a.upper_bound({x, y, r}) != a.end()) {
            int i = (*a.upper_bound({x, y, r}))[2];
            if (v[i][0] == x && v[i][1] == y) {
                // cerr << x << " " << y << ""  << r << "\n";
                // cerr << v[i][0] << " " << v[i][1] << " " << i << "\n";
                // cout << "pos " << i << "\n";
                ok = true;
            }
        }
        int tx = x - v[l - 1][0] + w[r + 1][0], ty = y - v[l - 1][1] + w[r + 1][1];
        // cout << tx << " " << ty << "\n";
        if (b.upper_bound({tx, ty, r + 1}) != b.end()) {
            int i = (*b.upper_bound({tx, ty, r + 1}))[2];
            if (l <= i && w[i][0] == tx && w[i][1] == ty) {
                ok = true;
            }
        }
        if (ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}