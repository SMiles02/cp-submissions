#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, ans = 15, cur;
    cin >> n;
    for (int i = 0; i < 15; ++i) {
        cur = 0;
        m = (n + i) % 32768;
        while (m != 0 && i + cur < 15) {
            m *= 2;
            m %= 32768;
            ++cur;
        }
        ans = min(ans, i + cur);
    }
    cout << ans << " ";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}