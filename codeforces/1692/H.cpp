#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

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
    cin >> n;
    int a[n + 1];
    array<int, 4> dp[n + 1], ans = {0, 69, 69, 69};
    map<int, int> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (m[a[i]]) {
            if (dp[m[a[i]]][0] - i + m[a[i]] + 2 > 0)
                dp[i] = {dp[m[a[i]]][0] - i + m[a[i]] + 2, dp[m[a[i]]][1], i, a[i]};
            else
                m[a[i]] = 0;
        }
        if (!m[a[i]])
            dp[i] = {1, i, i, a[i]};
        m[a[i]] = i;
        ans = max(ans, dp[i]);
        // for (int j : dp[i])
        //     cout << j << " ";
        // cout << "\n";
    }
    cout << ans[3] << " " << ans[1] << " " << ans[2] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}