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
    int n, k, x = 0, y;
    cin >> n >> k;
    string s;
    cin >> s;
    for (auto i : s)
        x += (i == '0');
    y = n - x;
    if (s[n - 1] == '0' && y) {
        for (int i = n - 2; i >= 0; --i)
            if (s[i] == '1' && n - 1 - i <= k) {
                swap(s[i], s[n - 1]);
                k -= n - 1 - i;
                break;
            }
    }
    if (s[0] == '0' && y - (s[n - 1] == '1')) {
        for (int i = 1; i < n; ++i)
            if (s[i] == '1' && i <= k) {
                swap(s[i], s[0]);
                k -= i;
                break;
            }
    }
    // cout << s << "\n";
    // cout << 11 * y << " " << (s[0] - '0') << " " << (s[n - 1] - '0') * 10 << "\n";
    cout << 11 * y - (s[0] - '0') - (s[n - 1] - '0') * 10 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}