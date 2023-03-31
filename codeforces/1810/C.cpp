#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
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
    int n, cnt = 0, c, d, unq = 0;
    cin >> n >> c >> d;
    int a[n * 2];
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++m[a[i]];
    }
    for (int i = 0; i < n; ++i)
        a[i + n] = i + 1;
    sort(a, a + n * 2);
    ll ans = 1e18, cur = 0;
    for (int i = 0; i < n * 2; ++i) {
        unq += min(m[a[i]], 1LL);
        cnt += m[a[i]];
        cur += 1LL * max(m[a[i]] - 1, 0LL) * c;
        ans = min(ans, cur + (n - cnt) * c + (a[i] - unq) * d);
        // cerr << cur + (n - cnt) * c + (a[i] - unq) * d << "\n";
        m[a[i]] = 0;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}