#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5 + 3;
int n, sub[N];
vector<int> e[N];
bitset<N> black;
string ans;

void dfs(int c, int p) {
    sub[c] = 1;
    for (int i : e[c]) {
        if (i != p && !black[i]) {
            dfs(i, c);
            sub[c] += sub[i];
        }
    }
}

int find_centroid(int c, int p, int t) {
    for (int i : e[c]) {
        if (i != p && !black[i] && sub[i] * 2 > t) {
            return find_centroid(i, c, t);
        }
    }
    return c;
}

void solve(int x, int id) {
    dfs(x, 0);
    int c = find_centroid(x, 0, sub[x]);
    ans[c] = 'A' + id;
    black[c] = 1;
    for (int i : e[c]) {
        if (!black[i]) {
            solve(i, id + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    ans = string(n + 1, '?');
    solve(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}