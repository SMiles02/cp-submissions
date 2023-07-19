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
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; ++i) {
        if (s[i] < s[i - 1]) {
            for (int j = 0; j < i - 1; ++j)
                cout << s[j];
            for (int j = i; j < n; ++j)
                cout << s[j];
            return 0;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        cout << s[i];
    }
    return 0;
}