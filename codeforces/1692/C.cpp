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

string s[8];

int cnt(int x) {
    int ret = 0;
    for (int i = 0; i < 8; ++i)
        ret += (s[x][i] == '#');
    return ret;
}

void solve() {
    bool ok = false;
    for (int i = 0; i < 8; ++i)
        cin >> s[i];
    for (int i = 0; i < 8; ++i) {
        if (cnt(i) == 2)
            ok = true;
        else if (ok && cnt(i) == 1) {
            for (int j = 0; j < 8; ++j)
                if (s[i][j] == '#') {
                    cout << i + 1 << " " << j + 1 << "\n";
                    return;
                }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}