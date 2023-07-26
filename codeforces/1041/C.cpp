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

void solve() {
    int n, m, d, days = 0;
    cin >> n >> m >> d;
    set<array<int, 2>> s;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert({x, i});
    }
    while (!s.empty()) {
        ++days;
        auto [cur, id] = *s.begin();
        s.erase(s.begin());
        ans[id] = days;
        while (s.lower_bound({cur + d + 1, -1}) != s.end()) {
            auto [new_cur, new_id] = *s.lower_bound({cur + d + 1, -1});
            s.erase(s.lower_bound({cur + d + 1, -1}));
            ans[new_id] = days;
            cur = new_cur;
        }
    }
    cout << days << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}