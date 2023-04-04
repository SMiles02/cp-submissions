#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const ll INF = 1e18;

ll ok_cnt(ll x) {
    ll cur = INF, cnt = 0, y = x;
    bool ok = true;
    while (cur > 0) {
        if (cur <= y) {
            if (x / cur == y / cur)
                cnt = x / cur - (x / cur > 4) - 1;
            else
                cnt = cnt * 9 + 8 + (x / cur - (x / cur > 4)) * ok;
        }
        // cout << cur  << " " << cnt << " " << ok << "\n";
        ok &= x / cur != 4;
        // cout << cur << " " << cnt << " " << cur << "\n";
        x %= cur;
        cur /= 10;
    }
    // cout << cnt << " " << ok << "\n";
    return cnt + ok;
}

void solve() {
    ll k, l = 1, r = INF, m;
    cin >> k;
    while (l < r) {
        m = l + (r - l) / 2;
        // cout << l << " " << r << " " << m << " " << ok_cnt(m) << "\n";
        if (ok_cnt(m) >= k)
            r = m;
        else
            l = m + 1;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // cout << ok_cnt(10);
    // return 0;
    // for (int i = 1; i <= 20; ++i)
    //     cout << i << ": " << ok_cnt(i) << "\n";
    // return 0;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}