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
                // cout << cur[j - 1] << " " << cur[j] << "\n";
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