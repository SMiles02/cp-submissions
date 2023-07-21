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

const int N = 2e5 + 1;
const ll INF = 1e18;
vector<array<int, 2>> e[N];
ll val[N];
bool ok;

void dfs(int c) {
    for (auto& [x, d] : e[c]) {
        if (val[x] == INF) {
            val[x] = val[c] + d;
            dfs(x);
        }
        else if (val[x] != val[c] + d) {
            ok = false;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        val[i] = INF;
        e[i].clear();
    }
    while (m--) {
        int a, b, d;
        cin >> a >> b >> d;
        e[a].push_back({b, d});
        e[b].push_back({a, -d});
    }
    ok = true;
    for (int i = 1; i <= n; ++i) {
        if (val[i] == INF) {
            val[i] = 0;
            dfs(i);
        }
    }
    if (ok) {
        cout << "YES\n";
    }
    else {
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