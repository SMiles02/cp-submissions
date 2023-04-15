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

int calc_mex(int n, vector<int>& v) {
    int mex = 0;
    map<int, int> m;
    for (auto i : v)
        ++m[i];
    while (m[mex] > 0)
        ++mex;
    return mex;
}

void solve() {
    int n, mex;
    cin >> n;
    map<int, int> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        ++m[v[i]];
    }
    mex = calc_mex(n, v);
    // cout << mex << "\n";
    if (mex == n)
        cout << "NO\n";
    else if (m[mex + 1] < 2)
        cout << "YES\n";
    else {
        int l = 1e9, r = -1e9;
        for (int i = 0; i < n; ++i)
            if (v[i] == mex + 1) {
                l = min(l, i);
                r = max(r, i);
            }
        for (int i = l; i <= r; ++i)
            v[i] = mex;
        if (calc_mex(n, v) == mex + 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}