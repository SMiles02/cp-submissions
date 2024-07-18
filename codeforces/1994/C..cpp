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
    int n, k, rp;
    cin >> n >> k;
    long long sum = (1LL * n * (n + 1)) / 2;
    vector<int> a(n + 1);
    vector<long long> p(n + 1), ans(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    rp = n;
    for (int i = n; i > 0; --i) {
        if (p[n] - p[i - 1] <= k) {
            continue;
        }
        while (p[rp - 1] - p[i - 1] > k) {
            --rp;
        } 
        ans[i] = ans[rp + 1] + 1;
        sum -= ans[i];
    }
    cout << sum << "\n";
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