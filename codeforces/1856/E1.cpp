#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5005;
int sub[N];
bitset<N> dp[N];
ll ans;
vector<int> e[N];

void dfs(int c) {
    dp[c][0] = 1;
    for (int i : e[c]) {
        dfs(i);
        for (int j = sub[c]; j >= 0; --j) {
            if (dp[c][j]) {
                dp[c][j + sub[i]] = 1;
            }
        }
        sub[c] += sub[i];
    }
    ll cur = 0;
    for (int i = 1; i < sub[c]; ++i) {
        if (dp[c][i]) {
            cur = max(cur, 1LL * i * (sub[c] - i));
        }
    }
    ans += cur;
    ++sub[c];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        e[p].push_back(i);
    }
    dfs(1);
    cout << ans;
    return 0;
}