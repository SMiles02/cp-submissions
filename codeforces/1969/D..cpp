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
    int n, k;
    ll ans = 0, cur = 0;
    cin >> n >> k;
    vector<array<int, 2>> a(n + 1);
    vector<ll> loss(n + 1, 1e18);
    if (k == 0) {
        loss[0] = 0;
    }
    priority_queue<ll> pq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
    }
    a[n] = {(int)1e9 + 5, (int)1e9 + 5};
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i) {
        cur += a[i][1];
        pq.push(a[i][1]);
        if (pq.size() > k) {
            cur -= pq.top();
            pq.pop();
        }
        if (pq.size() == k) {
            loss[i] = cur;
        }
    }
    cur = 0;
    for (int i = n; i > 0; --i) {
        cur += max(a[i][0] - a[i][1], 0);
        ans = max(ans, cur - loss[i - 1]);
    }
    cout << ans << "\n";
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