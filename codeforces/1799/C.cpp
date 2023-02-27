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
    string a, s = "", t = "", u = "";
    cin >> a;
    bool flag = false;
    vector<int> f(26);
    for (auto i : a)
        ++f[i - 'a'];
    for (int i = 0; i < 26; ++i) {
        if (flag)
            while (f[i] > 0) {
                s += alpha[i];
                --f[i];
            }
        while (f[i] > 1) {
            s += alpha[i];
            t += alpha[i];
            f[i] -= 2;
        }
        if (f[i]) {
            int cnt = 0;
            for (int j = i + 1; j < 26; ++j)
                cnt += f[j] > 0;
            if (cnt == 1)
                u += alpha[i];
            else if (cnt > 1) {
                t += alpha[i];
                flag = true;
            }
            else
                s += alpha[i];
        }
    }
    reverse(t.begin(), t.end());
    cout << s << u << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}