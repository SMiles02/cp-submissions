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
    int n, cur = 3;
    cin >> n;
    if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }
    vector<int> ans = {2};
    while (cur != n) {
        ll l = cur * 2 - 1, r = cur * 2 - 1;
        bool ok = false;
        for (int i = 0; i < 40; ++i) {
            if (l <= n && n <= r) {
                ok = true;
                break;
            }
            l = l * 2 - 1;
            r = r * 2 + 1;
        }
        if (ok) {
            ans.push_back(1);
            cur = cur * 2 - 1;
        }
        else {
            ans.push_back(2);
            cur = cur * 2 + 1;
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i << " ";
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