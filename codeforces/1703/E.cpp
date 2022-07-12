#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n, ans = 0, x, y;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vector<vector<bool>> done(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!done[i][j]) {
                // cout << i << " " << j << "\n";
                set<array<int, 2>> st;
                x = i;
                y = j;
                for (int k = 0; k < 4; ++k) {
                    st.insert({x, y});
                    swap(x, y);
                    y = n - 1 - y;
                }
                vector<int> cnt(2);
                for (auto k : st) {
                    done[k[0]][k[1]] = true;
                    ++cnt[s[k[0]][k[1]] - '0'];
                }
                ans += min(cnt[0], cnt[1]);
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