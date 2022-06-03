#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

string s;

int query() {
    cout << "? " << s << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, cur = 0, tmp;
    cin >> n >> m;
    s = string(m, '0');
    vector<int> v(m);
    vector<array<int, 2>> a(m);
    for (int i = 0; i < m; ++i) {
        s[i] = '1';
        v[i] = query();
        a[i] = {v[i], i};
        s[i] = '0';
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
        s[a[i][1]] = '1';
        tmp = query();
        if (tmp != cur + a[i][0])
            s[a[i][1]] = '0';
        else
            cur = tmp;
    }
    cout << "! " << cur << endl;
    return 0;
}