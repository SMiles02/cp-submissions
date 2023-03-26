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

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    ll cur = 1, tmp;
    deque<ll> d;
    for (int i = 0; i < n; ++i) {
        tmp = lcm(cur, b[i]);
        if ((1LL * a[i] * b[i]) % tmp) {
            ++ans;
            while (!d.empty())
                d.pop_back();
            cur = b[i];
        }
        else {
            bool ok = true;
            if (cur != tmp)
                for (auto j : d)
                    if (j % tmp)
                        ok = false;
            if (ok)
                cur = tmp;
            else {
                ++ans;
                while (!d.empty())
                    d.pop_back();
                cur = b[i];
            }
        }
        d.push_back(1LL * a[i] * b[i]);
    }
    cout << ans + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}