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
    int n, mx = 0;
    cin >> n;
    int a[n], t[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        mx = max(mx, t[i]);
    }
    double l = mx, r = mx + 1e8, m;
    for (int _ = 0; _ < 80; ++_) {
        m = l + (r - l) / 2;
        double x = 0, y = 1e8;
        for (int i = 0; i < n; ++i) {
            x = max(x, - m + t[i] + a[i]);
            y = min(y, m - t[i] + a[i]);
        }
        if (x > y)
            l = m;
        else
            r = m;
    }
    double x = 0, y = 1e8;
    for (int i = 0; i < n; ++i) {
        x = max(x, - l + t[i] + a[i]);
        y = min(y, l - t[i] + a[i]);
    }
    cout << fixed << setprecision(20) << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}