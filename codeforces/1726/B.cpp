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
    if (n > m || (n % 2 == 0 && m % 2 == 1)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (n & 1) {
        for (int i = 1; i < n; ++i) {
            cout << "1 ";
        }
        cout << m - n + 1 << "\n";
    }
    else {
        for (int i = 2; i < n; ++i) {
            cout << "1 ";
        }
        cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << "\n";
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