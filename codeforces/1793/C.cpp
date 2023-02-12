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
    int n, k, l, r, x, y;
    cin >> n;
    int p[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        p[k] = i;
    }
    l = x = 1;
    r = y = n;
    while (r - l > 2) {
        if (p[x] == l) {
            ++l;
            ++x;
        }
        else if (p[x] == r) {
            --r;
            ++x;
        }
        else if (p[y] == l) {
            ++l;
            --y;
        }
        else if (p[y] == r) {
            --r;
            --y;
        }
        else {
            cout << l << " " << r << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}