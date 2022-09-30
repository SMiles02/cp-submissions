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

ll score(deque<int> v, deque<int> w) {
    ll ans = 0;
    int last = -1;
    if (!v.empty()) {
        ans += v.front();
        v.pop_front();
        last = 0;
    }
    for (int i = 0; !v.empty() || !w.empty(); ++i) {
        if (i & 1) {
            if (!v.empty()) {
                ans += v.back();
                if (last == 1)
                    ans += v.back();
                v.pop_back();
                last = 0;
            }
        }
        else {
            if (!w.empty()) {
                ans += w.back();
                if (last == 0)
                    ans += w.back();
                w.pop_back();
                last = 1;
            }
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    deque<int> v, w;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (a[i])
            v.push_back(b[i]);
        else
            w.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    cout << max(score(v, w), score(w, v)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}