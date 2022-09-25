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
    string s;
    cin >> s;
    int n = s.size(), k;
    vector<int> ok = {-1}, v;
    for (auto i : s) {
        k = (i - '0');
        while (ok.back() > k) {
            v.push_back(min(ok.back() + 1, 9));
            ok.pop_back();
        }
        ok.push_back(k);
    }
    sort(v.rbegin(), v.rend());
    for (int i = 1; i < ok.size(); ++i) {
        while (!v.empty() && v.back() < ok[i]) {
            cout << v.back();
            v.pop_back();
        }
        cout << ok[i];
    }
    while (!v.empty()) {
        cout << v.back();
        v.pop_back();
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