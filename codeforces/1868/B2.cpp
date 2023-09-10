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
    int n, avg;
    cin >> n;
    ll sum = 0;
    vector<int> a(n), p(40), x(40), y(40);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n) {
        cout << "NO\n";
        return;
    }
    avg = sum / n;
    for (int i = 0; i < n; ++i) {
        if (a[i] == avg) {
            continue;
        }
        if (__builtin_popcount(abs(a[i] - avg)) == 1) {
            if (a[i] < avg) {
                ++p[__lg(avg - a[i]) + 1];
                --p[__lg(avg - a[i])];
                ++x[__lg(avg - a[i])];
            }
            else {
                --p[__lg(a[i] - avg) + 1];
                ++p[__lg(a[i] - avg)];
                ++y[__lg(a[i] - avg)];
            }
            continue;
        }
        bool done = false;
        for (int j = 0; j < 40; ++j) {
            for (int k = 0; k < 40; ++k) {
                if ((1LL << j) - (1LL << k) + a[i] == avg) {
                    done = true;
                    ++p[j];
                    --p[k];
                }
            }
        }
        if (!done) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < 40; ++i) {
        // cout << p[i] << " " << x[i] << " " << y[i] << "\n";
        if (i  + 1 < 40) {
            while (p[i] > 1 && y[i] > 0) {
                p[i] -= 2;
                ++p[i + 1];
                --y[i];
            }
            while (p[i] < -1 && x[i] > 0) {
                p[i] += 2;
                --p[i + 1];
                --x[i];
            }
        }
        // cout << p[i] << " " << x[i] << " " << y[i] << "\n";
        if (p[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}