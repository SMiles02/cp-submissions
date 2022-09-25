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
    string s, t;
    cin >> s;
    cin >> t;
    map<array<char, 2>, int> m;
    for (int i = 0; i < n; ++i)
        ++m[{min(s[i], t[n - i - 1]), max(s[i], t[n - i - 1])}];
    bool odd = n & 1;
    for (auto i : m) {
        // cout << i.first[0] << " " << i.first[1] << " " << i.second << "\n";
        if (i.second & 1) {
            if (i.first[0] != i.first[1] || !odd) {
                cout << "NO\n";
                return;
            }
            odd = false;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}