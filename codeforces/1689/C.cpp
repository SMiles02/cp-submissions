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

const int N = 3e5 + 1;
int sub[N], dp[N];
vector<int> e[N];

void dfs(int c, int p) {
    sub[c] = 1;
    vector<int> v;
    for (int i : e[c])
        if (i != p) {
            dfs(i, c);
            v.push_back(i);
            sub[c] += sub[i];
        }
    if (v.empty())
        dp[c] = 0;
    else if (v.size() == 1)
        dp[c] = sub[c] - 2;
    else
        dp[c] = max(dp[v[0]] + sub[v[1]] - 1, dp[v[1]] + sub[v[0]] - 1);
}

void solve() {
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    cout << dp[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}