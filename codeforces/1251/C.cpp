#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    deque<deque<int>> d;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || (s[i] - '0') % 2 != (s[i - 1] - '0') % 2) {
            d.push_back({});
        }
        d.back().push_back(s[i] - '0');
    }
    while (!d.empty()) {
        if (d[0].empty()) {
            d.pop_front();
            continue;
        }
        if (d.size() > 1 && d[1].empty()) {
            swap(d[0], d[1]);
            d.pop_front();
            if (d.size() > 1) {
                for (auto j : d[1]) {
                    d[0].push_back(j);
                }
                swap(d[0], d[1]);
                d.pop_front();
            }
        }
        if (d.size() == 1 || d[0][0] < d[1][0]) {
            cout << d[0][0];
            d[0].pop_front();
        }
        else {
            cout << d[1][0];
            d[1].pop_front();
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}