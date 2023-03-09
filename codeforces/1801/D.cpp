#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 801;
const ll INF = 1e18;
array<ll, 2> ans[N];
bitset<N> check, new_check;
int a[N];
ll d[N][N];

bool best(array<ll, 2> &x, array<ll, 2> y) {
    if (y[0] < x[0] || (x[0] == y[0] && y[1] > x[1])) {
        x = y;
        return true;
    }
    return false;
}

void solve() {
    int n, m, p, x, y, z;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j <= n; ++j)
            d[i][j] = INF;
        d[i][i] = 0;
        ans[i] = {INF, INF};
        check[i] = new_check[i] = 0;
    }
    for (int j = 0; j < m; ++j) {
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], (ll)z);
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    ans[1] = {0, p};
    check[1] = 1;
    for (int _ = 1; _ < n; ++_) {
        for (int i = 1; i <= n; ++i)
            if (check[i])
                for (int j = 1; j <= n; ++j) 
                    if (d[i][j] < INF) {
                        ll x, y;
                        if (ans[i][1] < d[i][j]) {
                            x = (d[i][j] - ans[i][1] + a[i] - 1) / a[i];
                            y = 1LL * x * a[i];
                        }
                        else {
                            x = 0;
                            y = 0;
                        }
                        if (best(ans[j], {ans[i][0] + x, ans[i][1] + y - d[i][j]}))
                            new_check[j] = 1;
                    }
        swap(check, new_check);
        for (int i = 1; i <= n; ++i)
            new_check[i] = 0;
    }
    if (ans[n][0] == INF)
        ans[n][0] = -1;
    cout << ans[n][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}