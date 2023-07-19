#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            v[j].push_back(x);
        }
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        sort(v[i].begin(), v[i].end());
        for (int j = 0; j < n; ++j) {
            ans += 1LL * (j * 2 - n + 1) * v[i][j];
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}