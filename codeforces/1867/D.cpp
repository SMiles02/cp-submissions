#include <bits/stdc++.h>
#define ll long long
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

const int N = 1e5 + 1, L = 19;
int a[N], to[N], up[L][N];

int lift(int x, int l) {
    for (int i = 0; i < L; ++i) {
        if ((1 << i) & l) {
            x = up[i][x];
        }
    }
    return x;
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        to[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++to[a[i]];
    }
    if (k == 1) {
        for (int i = 1; i <= n; ++i) {
            if (a[i] != i) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    vector<int> v;
    vector<bool> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (to[i] == 0) {
            v.push_back(i);
        }
    }
    while (!v.empty()) {
        int x = v.back();
        v.pop_back();
        b[x] = true;
        if (--to[a[x]] == 0) {
            v.push_back(a[x]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!b[i]) {
            int cur = i, sz = 0;
            while (!b[cur]) {
                b[cur] = true;
                cur = a[cur];
                ++sz;
            }
            if (sz != k) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}