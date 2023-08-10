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
    string s;
    cin >> s;
    s = "0" + s;
    int n = s.size(), zero;
    zero = n;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i + 1] > '4' && s[i] < '9') {
            ++s[i];
            zero = i + 1;
        }
    }
    if (s[0] != '0') {
        cout << 1;
    }
    for (int i = 1; i < n; ++i) {
        if (zero <= i) {
            cout << 0;
        }
        else {
            cout << s[i];
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