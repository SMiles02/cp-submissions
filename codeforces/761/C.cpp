// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 1);
    int a[n + 1][3];
    ll dp[n + 1][8];
    for (int j = 0; j < 8; ++j)
        dp[0][j] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        for (int j = 0; j < 3; ++j)
            a[i][j] = INF;
        for (int j = 0; j < m; ++j) {
            if ('0' <= s[i][j] && s[i][j] <= '9')
                a[i][0] = min({a[i][0], j, m - j});
            else if ('a' <= s[i][j] && s[i][j] <= 'z')
                a[i][1] = min({a[i][1], j, m - j});
            else
                a[i][2] = min({a[i][2], j, m - j});
        }
        // for (int j = 0; j < 3; ++j)
        //     cout << a[i][j] << " ";
        // cout << "\n";
        for (int j = 0; j < 8; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j & 1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i][0]);
            if (j & 2)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 2] + a[i][1]);
            if (j & 4)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 4] + a[i][2]);
        }
    }
    cout << dp[n][7];
    return 0;
}