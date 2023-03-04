#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool is_ok(string s, map<string, int> m) {
    for (int i = 0; i < s.size(); ++i)
        if (s[i] != s[s.size() - i - 1])
            return false;
    string t = "";
    for (int i = 0; i + 1 < s.size(); ++i) {
        t += s[i];
        if (--m[t] < 0)
            return false;
    }
    for (int i = 1; i < s.size(); ++i) {
        string u = "";
        for (int j = i; j < s.size(); ++j)
            u += s[j];
        if (--m[u] < 0)
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    map<string, int> m;
    vector<string> v, w;
    for (int i = 0; i < n * 2 - 2; ++i) {
        string s;
        cin >> s;
        ++m[s];
        if (s.size() == 1)
            v.push_back(s);
        if (s.size() == n - 1)
            w.push_back(s);
    }
    if (n == 2) {
        if (v[0] == v[1])
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }
    for (auto i : v)
        for (auto j : w) {
            string tmp = i;
            tmp += j;
            // cout << tmp << endl;
            if (is_ok(tmp, m)) {
                cout << "YES\n";
                return;
            }
        }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}