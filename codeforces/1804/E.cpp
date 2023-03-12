#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m, ans[N], cmp[1 << N];
bitset<N> dp[1 << N], e[N];

void print_ans(int cycle_members) {
    // cerr << cycle_members << "\n";
    for (int i = 0; i < n; ++i)
        if (!(cycle_members & (1 << i)))
            for (int j = 0; j < n; ++j)
                if ((cycle_members & (1 << j)) && e[i][j])
                    ans[i] = j;
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        assert(ans[i] != -1);
        cout << ans[i] + 1 << " ";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        ans[i] = -1;
    while (m--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        e[x][y] = e[y][x] = 1;
    }
    for (int i = 1; i < (1 << n); ++i) {
        if (__builtin_popcount(i) == 1) {
            int j = -1;
            for (int k = 0; k < n; ++k)
                if ((1 << k) == i)
                    j = k;
            assert(j != -1);
            cmp[i] = i;
            for (int k = 0; k < n; ++k)
                if (e[j][k])
                    cmp[i] |= 1 << k;
        }
        else {
            int j = i & -i;
            cmp[i] = cmp[j] | cmp[i ^ j];
        }
        // cout << i << ": " << cmp[i] << "\n"; 
    }
    for (int x = 0; x < n; ++x) {
        for (int i = 0; i < (1 << n); ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = 0;
        dp[1 << x][x] = 1;
        for (int i = 1; i < (1 << n); ++i)
            for (int y = 0; y < n; ++y)
                if (dp[i][y]) {
                    if (e[y][x] && cmp[i] == (1 << n) - 1) {
                        // rebuild cycle of marked nodes
                        ans[x] = y;
                        int cur_cmp = i, last_node = y;
                        while (__builtin_popcount(cur_cmp) > 1) {
                            for (int j = 0; j < n; ++j)
                                if ((cur_cmp & (1 << j)) && e[last_node][j] && dp[cur_cmp ^ (1 << last_node)][j]) {
                                    ans[last_node] = j;
                                    cur_cmp ^= 1 << last_node;
                                    last_node = j;
                                    break;
                                }
                        }
                        print_ans(i);
                        return 0;
                    }
                    for (int j = 0; j < n; ++j)
                        if (e[y][j] && !(i & (1 << j)))
                            dp[i | (1 << j)][j] = 1;
                }
    }
    cout << "No";
    return 0;
}