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
    int n, k;
    cin >> n;
    vector<int> v(10);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        ++v[k % 10];
    }
    for (int i = 0; i < 10; ++i)
        if (v[i]) {
            --v[i];
            for (int j = i; j < 10; ++j)
                if (v[j]) {
                    --v[j];
                    for (int k = j; k < 10; ++k)
                        if (v[k] && (i + j + k) % 10 == 3) {
                            cout << "YES\n";
                            return;
                        }
                    ++v[j];
                }
            ++v[i];
        }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}