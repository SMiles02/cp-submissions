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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k & 1) {
        string a = "", b = "";
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                b += s[i];
            }
            else {
                a += s[i];
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                cout << b[i / 2];
            }
            else {
                cout << a[i / 2];
            }
        }
        cout << "\n";
    }
    else {
        sort(s.begin(), s.end());
        cout << s << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}