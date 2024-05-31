#include <bits/stdc++.h>
using namespace std;

struct euler_path {
    int n;
    vector<vector<bool>> edge;
    euler_path(int n) : n(n), edge(n + 1, vector<bool>(n + 1)) {}
    void add_edge(int x, int y) {
        edge[x][y] = edge[y][x] = true;
    }
    void cycle(deque<int>& d) {
        d.push_front(d.back());
        d.pop_back();
    }
    deque<int> find_path(int src = 1) {
        int not_done = 0;
        deque<int> d = {-1, src};
        vector<int> s(n + 1);
        vector<vector<bool>> e = edge;
        for (int i = 0; i <= n; ++i) {
            bool has_edges = false;
            for (int j = 0; j <= n; ++j) {
                has_edges |= e[i][j];
            }
            not_done += has_edges;
        }
        while (not_done > 0) {
            int x = d.back();
            if (x == -1) {
                cycle(d);
            }
            while (s[x] <= n && !e[x][s[x]]) {
                ++s[x];
                if (s[x] > n) {
                    --not_done;
                }
            }
            if (s[x] > n) {
                cycle(d);
            }
            else {
                e[x][s[x]] = e[s[x]][x] = false;
                d.push_back(s[x]);
            }
        }
        while (d[0] != -1) {
            cycle(d);
        }
        d.pop_front();
        return d;
    }
};

const int S = 12600;
bitset<S> sieve;
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
    euler_path graph(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (m % 2 == 0 && i > 1 && ((i + 1 == j && i % 2 == 0) || (i - 1 == j && i % 2 == 1))) {
                continue;
            }
            graph.add_edge(i, j);
        }
    }
    deque<int> path = graph.find_path(0);
    for (int i = 0; i < n; ++i) {
        cout << primes[path[i]] << " ";
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