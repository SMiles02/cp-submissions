#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
vector<int> e[N];
int col[N];
bool is_bp;

void dfs(int c, int x) {
    col[c] = x;
    for (int i : e[c]) {
        if (col[i]) {
            if (col[c] == col[i])
                is_bp = false;
        }
        else
            dfs(i, 3 - x);
    }
}

void solve() {
    int n;
    cin >> n;
    int a[n][2];
    vector<int> v(n + 1);
    vector<vector<int>> f(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        f[a[i][0]].push_back(i + 1);
        f[a[i][1]].push_back(i + 1);
    }
    for (int i = 1; i <= n; ++i)
        if (f[i].size() > 2) {
            cout << "NO\n";
            return;
        }
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        col[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < f[i].size(); ++j)
            for (int k = 0; k < j; ++k) {
                e[f[i][j]].push_back(f[i][k]);
                e[f[i][k]].push_back(f[i][j]);
            }
    is_bp = true;
    for (int i = 1; i <= n; ++i)
        if (!col[i])
            dfs(i, 1);
    if (is_bp)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}