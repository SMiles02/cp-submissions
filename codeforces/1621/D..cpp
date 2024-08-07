#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<vector<int>> a(n * 2, vector<int>(n * 2));
    for (int i = 0; i < n * 2; ++i) {
        for (int j = 0; j < n * 2; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = n; i < n * 2; ++i) {
        for (int j = n; j < n * 2; ++j) {
            ans += a[i][j];
        }
    }
    cout << ans + min({a[0][n], a[0][n * 2 - 1], a[n - 1][n], a[n - 1][n * 2 - 1], a[n][0], a[n][n - 1], a[n * 2 - 1][0], a[n * 2 - 1][n - 1]}) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}