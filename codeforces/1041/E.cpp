#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x = 1;
    cin >> n;
    vector<array<int, 2>> e(n - 1), ans;
    vector<int> cnt(n + 1);
    vector<bool> done(n + 2);
    for (auto& [x, y] : e) {
        cin >> x >> y;
        if (max(x, y) != n || x == y) {
            cout << "NO";
            return 0;
        }
        done[x] = done[y] = true;
        ++cnt[min(x, y)];
    }
    for (int i = 1; i < n; ++i) {
        if (done[i]) {
            vector<int> cur = {n};
            for (int j = 1; j < cnt[i]; ++j) {
                while (done[x]) {
                    ++x;
                }
                if (x > i) {
                    cout << "NO";
                    return 0;
                }
                cur.push_back(x);
                done[x] = true;
            }
            cur.push_back(i);
            for (int j = 1; j < cur.size(); ++j) {
                ans.push_back({cur[j - 1], cur[j]});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!done[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (auto& [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
    return 0;
}