#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
bitset<2> dp[N][2], source[N][2][2][2];

void print(int i, int x, int y) {
    cerr << i << " " << x << " " << y << ": " << dp[i][x][y] << "\n";
}

void solve() {
    int n, cur_len = 0;
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n + 5; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = 0;
                for (int x = 0; x < 2; ++x) {
                    for (int y = 0; y < 2; ++y) {
                        source[i][j][k][x][y] = 0;
                    }
                }
            }
        }
    }
    dp[0][0][1] = 1;
    for (int c = 0; c < n; ++c) {
        if (s[c] == '+') {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    if (dp[cur_len][i][j] == 0) {
                        continue;
                    }
                    for (int x = 0; x < 2; ++x) {
                        int y = 1;
                        if (i > x || j == 0) {
                            y = 0;
                        }
                        // cout << i << " " << j << " " << x << " " << y << "\n";
                        dp[cur_len + 1][x][y] = 1;
                        source[cur_len + 1][x][y][i][j] = 1;
                    }
                }
            }
            ++cur_len;
            // for (int i = 0; i < 2; ++i) {
            //     for (int j = 0; j < 2; ++j) {
            //         cout << i << " " << j << ": " << dp[cur_len][i][j] << "\n";
            //     }
            // }
            // cout << "\n";
        }
        else if (s[c] == '-') {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    dp[cur_len - 1][i][j] = 0;
                }
            }
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    for (int i = 0; i < 2; ++i) {
                        for (int j = 0; j < 2; ++j) {
                            // if (x == 0 && y == 0 && i == 1 && j == 1) {
                            //     cerr << "test\n";
                            //     cerr << dp[cur_len][x][y] << " " << source[cur_len][x][y][i][j] << "\n";
                            // }
                            if (dp[cur_len][x][y] == 1 && source[cur_len][x][y][i][j] == 1) {
                                dp[cur_len - 1][i][j] = 1;
                                // print(cur_len - 1, i, j);
                            }
                            source[cur_len][x][y][i][j] = 0;
                        }
                    }
                    dp[cur_len][x][y] = 0;
                }
                // print(cur_len - 1, 1, 1);
            }
            --cur_len;
            // print(cur_len, 1, 1);
            // for (int i = 0; i < 2; ++i) {
            //     for (int j = 0; j < 2; ++j) {
            //         cout << i << " " << j << ": " << dp[cur_len][i][j] << "\n";
            //     }
            // }
            // cout << "\n";
        }
        else {
            for (int x = 0; x < 2; ++x) {
                dp[cur_len][x][1 - (s[c] - '0')] = 0;
            }
            bool found = false;
            for (int x = 0; x < 2; ++x) {
                if (dp[cur_len][x][(s[c] - '0')]) {
                    found = true;
                }
            }
            if (!found) {
                cout << "NO\n";
                return;
            }
            // for (int i = 0; i < 2; ++i) {
            //     for (int j = 0; j < 2; ++j) {
            //         cout << i << " " << j << ": " << dp[cur_len][i][j] << "\n";
            //     }
            // }
            // cout << "\n";
        }
        // if (c == 1) {
        //     cerr << source[cur_len][0][0][1][1] << "\n";
        // }
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