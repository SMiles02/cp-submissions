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
    int n, m, k, x = 0, y = 0, t;
    cin >> n >> m >> k;
    int p[2];
    p[0] = p[1] = 0;
    string s[2], ans = "";
    cin >> s[0];
    cin >> s[1];
    sort(s[0].begin(), s[0].end());
    sort(s[1].begin(), s[1].end());
    while (p[0] < n && p[1] < m) {
        if (s[0][p[0]] < s[1][p[1]])
            t = 0;
        else
            t = 1;
        if (t == x) {
            if (y == k) {
                x = 1 - t;
                y = 0;
            }
        }
        else {
            x = t;
            y = 0;
        }
        ++y;
        ans += s[x][p[x]++];
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