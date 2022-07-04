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

const int N = 55;
int a[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    a[0][0] = 1;
    a[0][1] = 0;
    a[0][2] = 0;
    a[0][3] = 1;
    for (int j = 4; j < N; ++j)
        a[0][j] = a[0][j - 4];
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            if (i % 4 == 0 || i % 4 == 3)
                a[i][j] = a[0][j];
            else
                a[i][j] = 1 - a[0][j];
        }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}