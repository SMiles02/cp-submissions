#include <bits/stdc++.h>
using namespace std;

const int N = 3e5, M = 15 * 1e6 + 1;
int a[N], pf[M], cnt[M];
vector<int> p;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < M; ++i) {
        if (pf[i] == 0) {
            pf[i] = i;
            p.push_back(i);
        }
        for (int j = 0; j < p.size() && p[j] <= pf[i] && i * p[j] < M; ++j) {
            pf[i * p[j]] = p[j];
        }
    }
    int n, g = 0, ans = 1e9;
    bool all_one = true;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        all_one &= (a[i] /= g) == 1;
        while (a[i] > 1) {
            int cur_factor = pf[a[i]];
            ++cnt[cur_factor];
            while (a[i] % cur_factor == 0) {
                a[i] /= cur_factor;
            }
        }
    }
    for (int i : p) {
        ans = min(ans, n - cnt[i]);
    }
    if (all_one) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}