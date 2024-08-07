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

string alpha = "abcdefghijklmnopqrstuvwxyz";

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> cnt(k);
    vector<vector<int>> f(k, vector<int>(26));
    string s, t(k, 'a');
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if ((i % k) * 2 < k) {
            ++f[i % k][s[i] - 'a'];
            ++cnt[i % k];
        }
        else {
            ++f[k - (i % k) - 1][s[i] - 'a'];
            ++cnt[k - (i % k) - 1];
        }
    }
    for (int i = 0; i * 2 < k; ++i) {
        int id = 0;
        for (int j = 1; j < 26; ++j) {
            if (f[i][j] > f[i][id]) {
                id = j;
            }
        }
        ans += cnt[i] - f[i][id];
    }
    cout << ans << "\n";
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