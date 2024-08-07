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

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n, x = 1, y = 2, g, a, b;
    cin >> n;
    g = query(x, y);
    for (int i = 3; i <= n; ++i) {
        a = query(x, i);
        b = query(y, i);
        if (a == max({a, b, g})) {
            g = a;
            y = i;
        }
        else if (b == max({a, b, g})) {
            g = b;
            x = i;
        }
    }
    cout << "! " << x << " " << y << endl;
    int ans;
    cin >> ans;
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}