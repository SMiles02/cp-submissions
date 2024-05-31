#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int S = 12600, N = 1504;
bitset<S> sieve;
bitset<N> e[N];
vector<int> primes;

int f(int n) {
    if (n & 1) {
        return (n * (n + 1)) / 2 + 1;
    }
    return (n * n) / 2 + 2;
}

void cycle(deque<int>& d) {
    d.push_front(d.back());
    d.pop_back();
}

void solve() {
    int n, l = 1, r = primes.size(), m, done = 0;
    cin >> n;
    if (n == 2) {
        cout << "43770 43770\n";
        return;
    }
    while (l < r) {
        m = l + (r - l) / 2;
        if (f(m) < n) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    m = l;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            e[i][j] = 1;
        }
        if (m % 2 == 0 && i % 2 == 1 && i > 1) {
            e[i][i - 1] = e[i - 1][i] = 0;
        }
    }
    deque<int> d = {-1, 0};
    vector<int> s(m);
    while (done < m) {
        int x = d.back();
        if (x == -1) {
            cycle(d);
        }
        // cerr << x << endl;
        while (s[x] < m && !e[x][s[x]]) {
            ++s[x];
            if (s[x] == m) {
                ++done;
            }
        }
        if (s[x] == m) {
            cycle(d);
        }
        else {
            e[x][s[x]] = e[s[x]][x] = 0;
            d.push_back(s[x]);
            // cerr << x << " " << s[x] << endl;
        }
    }
    while (d[0] != -1) {
        cycle(d);
    }
    for (int i = 1; i <= n; ++i) {
        cout << primes[d[i]] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < S; ++i) {
        if (sieve[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i; j < S; j += i) {
            sieve[j] = 1;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}