#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

ll check(vector<ll>& v, ll g) {
    ll ans = 0;
    sort(v.begin(), v.end());
    for (ll i : v) {
        ans += (v.back() - i) / g;
    }
    return ans;
}

void solve() {
    int n;
    ll g = 0;
    cin >> n;
    vector<ll> v, x, y;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        v.push_back(x);
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; ++i) {
        g = __gcd(g, v[i] - v[i - 1]);
    }
    x = y = v;
    x.push_back(v[0] - g);
    y.push_back(v.back() + g);
    for (int i = 1; i < n; ++i) {
        if (x[i] - x[i - 1] != g) {
            x[n] = x[i] - g;
        }
    }
    cout << min(check(x, g), check(y, g)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}