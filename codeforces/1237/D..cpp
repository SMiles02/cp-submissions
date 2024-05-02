#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

template <class S, S (*op)(S, S), S (*e)()> struct sparse_table {
    int n, lg;
    vector<vector<S>> st;
    sparse_table(int n) : n(n), lg((int)log2(n) + 2), st((int)log2(n) + 2, vector<int>(n, e())) {}
    void set(int i, S x) {
        st[0][i] = x;
    }
    void build() {
        for (int j = 1; j < lg; ++j) {
            for (int i = n - 1; i - (1 << j) + 1 >= 0; --i) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i - (1 << (j - 1))]);
            }
        }
    }
    S query(int l, int r) {
        int cur_lg = (int)log2(r - l + 1);
        return op(st[cur_lg][l], st[cur_lg][r - (1 << cur_lg) + 1]);
    }
};

// basic operation
int op(int a, int b) { return max(a, b); }

// op(anything, e()) = anything
int e() { return -1; }

// currently query max
// note: range l, r means [l, r]

// Constructor:
// (1) sparse_table<S, op, e> seg(int n)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m = 0;
    cin >> n;
    vector<int> a(n), dp(n, 1e9);
    sparse_table<int, op, e> st(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m = max(m, a[i]);
        st.set(i, a[i]);
        st.set(i + n, a[i]);
    }
    st.build();
    for (int i = 0; i < n; ++i) {
        if (a[i] * 2 >= m) {
            continue;
        }
        // cerr << "Trying " << i << "\n";
        int cur = i + n;
        for (int j = 16; j >= 0; --j) {
            if (cur - (1 << j) >= 0 && a[i] * 2 >= st.st[j][cur - 1]) {
                cur -= 1 << j;
            }
        }
        // cerr << ((cur - 1) % n) << "\n";
        dp[(cur - 1) % n] = min(dp[(cur - 1) % n], i + n - cur + 1);
    }
    for (int _ = 0; _ < 3; ++_) {
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], dp[(i + 1) % n] + 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dp[i] == 1e9) {
            dp[i] = -1;
        }
        cout << dp[i] << " ";
    }
    cout << "\n";
    return 0;
}