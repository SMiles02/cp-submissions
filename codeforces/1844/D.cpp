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

string alpha = "abcdefghijklmnopqrstuvwxyz";

void solve() {
    int n;
    cin >> n;
    vector<int> v = {1};
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            v.push_back(i);
            v.push_back(n / i);
        }
    }
    string ans = "a";
    for (int i = 1; i < n; ++i) {
        vector<bool> done(26);
        for (int j : v) {
            if (i >= j) {
                done[ans[i - j] - 'a'] = true;
            }
        }
        for (int j = 0; j < 26; ++j) {
            if (!done[j]) {
                ans += alpha[j];
                break;
            }
        }
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