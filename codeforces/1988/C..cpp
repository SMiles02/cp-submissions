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
    ll n;
    cin >> n;
    int k = __builtin_popcountll(n);
    if (k == 1) {
        cout << "1\n" << n << "\n";
        return;
    }
    cout << k + 1 << "\n";
    for (int i = 0; i <= k; ++i) {
        ll ans = 0;
        int cnt = 0;
        for (int j = 59; j >= 0; --j) {
            if (n & (1LL << j)) {
                if ((cnt++) != i) {
                    ans ^= 1LL << j;
                }
            }
        }
        cout << ans << " ";
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