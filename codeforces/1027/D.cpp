// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1;
ll ans = 0;
int c[N], a[N], cur, done[N];

void addMin(int x) {
    int y = x, tmp = c[x];
    while (a[y] != x) {
        y = a[y];
        tmp = min(tmp, c[y]);
    }
    ans += tmp;
}

void dfs(int x) {
    done[x] = cur;
    if (!done[a[x]])
        dfs(a[x]);
    else if (done[a[x]] == cur)
        addMin(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        if (!done[i]) {
            ++cur;
            dfs(i);
        }
    cout << ans;
    return 0;
}