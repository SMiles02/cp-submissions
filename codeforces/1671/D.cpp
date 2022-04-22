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

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n], mn = 2e5, mx = 1;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0)
            ans += abs(a[i] - a[i - 1]);
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    // cout << ans << "\n";
    if (x < mn) {
        // cout << "oop\n";
        ans += min((mn - 1) * 2, min(a[0], a[n - 1]) - 1);
    }
    else {
        if (1 < mn)
            ans += min((mn - 1) * 2, min(a[0], a[n - 1]) - 1);
        if (mx < x)
            ans += min((x - mx) * 2, x - max(a[0], a[n - 1]));
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