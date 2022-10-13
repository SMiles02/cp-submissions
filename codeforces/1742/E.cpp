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
    int n, q, x, l, r, m;
    cin >> n >> q;
    ll p[n + 1];
    int mx[n + 1];
    p[0] = 0;
    mx[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        p[i] = p[i - 1] + x;
        mx[i] = max(mx[i - 1], x);
    }
    while (q--) {
        cin >> x;
        l = 0;
        r = n;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (mx[m] > x)
                r = m - 1;
            else
                l = m;
        }
        cout << p[l] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}