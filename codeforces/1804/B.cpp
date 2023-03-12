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
    int n, k, d, w, x = 0, y, ans = 0;
    cin >> n >> k >> d >> w;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    while (x < n) {
        ++ans;
        for (int i = x; i < min(x + k, n); ++i) {
            if (max(a[x] + w, a[i]) <= min(a[x] + w + d, a[i] + w))
                y = i + 1;
            else
                break;
        }
        x = y;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}