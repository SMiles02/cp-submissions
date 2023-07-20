#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int a[N][N], s[N];

void solve() {
    int n, ans = 1e9;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        s[i] = 0;
        for (int j = 0; j < n; ++j) {
            a[i][j] = t[j] == '1';
            s[i] += a[i][j];
        }
    }
    for (int x = 0; x < n; ++x) {
        int cur = 0;
        for (int i = 0, j = x; i < n; ++i, ++j) {
            if (j == n) {
                j = 0;
            }
            cur += s[i];
            if (a[i][j] == 0) {
                ++cur;
            }
            else {
                --cur;
            }
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}