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
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        if (m == 1) {
            cout << "0\n";
        }
        else {
            cout << "2\n";
        }
        for (int i = 0; i < m; ++i) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    if (m == 1) {
        cout << "0\n";
        for (int i = 0; i < n; ++i) {
            cout << "0\n";
        }
        return;
    }
    cout << min(m, 2 + n - 1) << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (j + min(i, m - 2) + m) % m << " ";
        }
        cout << "\n";
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