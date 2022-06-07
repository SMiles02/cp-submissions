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

ll lcm(ll x, ll y) {
    return (x / gcd(x, y)) * y;
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

struct DSU {
    vector<int> pt, rk;
    DSU(int n) : pt(n + 1), rk(n + 1, 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

void solve() {
    int n, m;
    ll ans = 1;
    cin >> n;
    string r, s, t, u;
    cin >> s;
    int a[n];
    bool ok;
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        dsu.unite(i, a[i]);
    }
    for (int k = 0; k < n; ++k)
        if (dsu.find_set(k) == k) {
            vector<int> v = {k};
            t = s[k];
            while (a[v.back()] != k) {
                v.push_back(a[v.back()]);
                t += s[v.back()];
            }
            m = v.size();
            u = r = t;
            // for (int i : v)
            //     cout << i << " ";
            // cout << "\n" << t << "\n";
            for (int j = 1; j <= m; ++j) {
                for (int i = 0; i + 1 < m; ++i)
                    r[i] = u[i + 1];
                r[m - 1] = u[0];
                // cout << j << ": " << r << "\n";
                if (r == t) {
                    ans = lcm(ans, j);
                    break;
                }
                u = r;
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