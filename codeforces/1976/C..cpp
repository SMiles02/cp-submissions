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

void solve() {
    int n, m, x = 0, y = 0, cnt = 0, last = 0;
    cin >> n >> m;
    ll tot = 0;
    vector<int> a(n + m + 1), b(n + m + 1);
    vector<ll> ans(n + m + 1);
    for (int i = 0; i < n + m + 1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n + m + 1; ++i) {
        cin >> b[i];
        x += a[i] > b[i];
        y += a[i] < b[i];
    }
    if (x > n) {
        for (int i = 0; i < n + m + 1; ++i) {
            if (a[i] > b[i] && cnt < n + 1) {
                ++cnt;
                last = i;
                tot += a[i];
            }
            else {
                tot += b[i];
            }
        }
        for (int i = 0; i < n + m + 1; ++i) {
            if (a[i] > b[i] && i <= last) {
                ans[i] = tot - a[i];
            }
            else {
                ans[i] = tot - b[i] + b[last] - a[last];
            }
        }
    }
    else {
        for (int i = 0; i < n + m + 1; ++i) {
            if (b[i] > a[i] && cnt < m + 1) {
                ++cnt;
                last = i;
                tot += b[i];
            }
            else {
                tot += a[i];
            }
        }
        for (int i = 0; i < n + m + 1; ++i) {
            if (b[i] > a[i] && i <= last) {
                ans[i] = tot - b[i];
            }
            else {
                ans[i] = tot - a[i] + a[last] - b[last];
            }
        }
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
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