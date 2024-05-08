#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 200;
int d[N];
vector<int> e[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > 0) {
            b.push_back(a[i]);
        }
    }
    for (int j = 0; j < 60; ++j) {
        int cnt = 0;
        for (ll i : b) {
            if (i & (1LL << j)) {
                ++cnt;
            }
        }
        if (cnt > 2) {
            cout << "3\n";
            return 0;
        }
    }
    vector<array<int, 2>> edges;
    for (int i = 0; i < b.size(); ++i) {
        for (int j = i + 1; j < b.size(); ++j) {
            if (b[i] & b[j]) {
                e[i].push_back(j);
                e[j].push_back(i);
                edges.push_back({i, j});
            } 
        }
    }
    int ans = 1000;
    for (auto [cur, tar] : edges) {
        // cout << cur << " " << tar << " !!!\n";
        queue<int> q;
        for (int i = 0; i < b.size(); ++i) {
            d[i] = 1000;
        }
        d[cur] = 0;
        q.push(cur);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            // cout << x << ": " << d[x] << "\n";
            for (int i : e[x]) {
                if ((x == cur && i == tar) || d[i] <= d[x] + 1) {
                    continue;
                }
                d[i] = d[x] + 1;
                q.push(i);
            }
        }
        ans = min(ans, d[tar] + 1);
    }
    if (ans == 1000) {
        ans = -1;
    }
    cout << ans << "\n";
    return 0;
}