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

void solve() {
    int n, x, y;
    cin >> n;
    int p[n + 1], q[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    if (n == 1) {
        cout << "-1\n";
        return;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i)
        pq.push(i);
    for (int i = 1; i < n - 1; ++i) {
        if (pq.top() == p[i]) {
            x = pq.top();
            pq.pop();
            q[i] = pq.top();
            pq.pop();
            pq.push(x);
        }
        else {
            q[i] = pq.top();
            pq.pop();
        }
        // cout << q[i] << " ";
    }
    // cout << "\n";
    x = pq.top();
    pq.pop();
    y = pq.top();
    pq.pop();
    // cout << x << " " << y << "\n";
    if (x == p[n - 1] || y == p[n]) {
        q[n - 1] = y;
        q[n] = x;
    }
    else {
        q[n - 1] = x;
        q[n] = y;
    }
    for (int i = 1; i <= n; ++i)
        cout << q[i] << " ";
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