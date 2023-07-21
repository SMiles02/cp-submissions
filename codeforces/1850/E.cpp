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

const int N = 2e5 + 1;
int n, a[N];

ll check(ll m) {
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (m * 2 + a[i]) * (m * 2 + a[i]); 
    }
    return sum;
}

void solve() {
    ll c, l = 0, r = 1;
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (check(r * 2) <= c) {
        r *= 2;
    }
    r *= 2;
    while (l < r) {
        ll m = l + (r - l) / 2 + 1;
        if (check(m) <= c) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}