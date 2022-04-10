// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, x, y, dn;
    cin >> n >> k >> x;
    vector<int> f(1024);
    for (int i = 0; i < n; ++i) {
        cin >> y;
        ++f[y];
    }
    while (k--) {
        // for (int j = 0; j < 1024; ++j) {
        //     for (int x = 0; x < f[j]; ++x)
        //         cout << j << " ";
        // }
        // cout << "\n"; 
        vector<int> g(1024, 0);
        dn = 0;
        for (int i = 0; i < 1024; ++i) {
            if (dn & 1) {
                g[i] += (f[i] + 1) / 2;
                g[i ^ x] += f[i] / 2;
            }
            else {
                g[i ^ x] += (f[i] + 1) / 2;
                g[i] += f[i] / 2;
            }
            dn += f[i];
        }
        swap(f, g);
        // for (int j = 0; j < 1024; ++j) {
        //     for (int x = 0; x < f[j]; ++x)
        //         cout << j << " ";
        // }
        // cout << "\n"; 
    }
    for (int i = 1023; i >= 0; --i)
        if (f[i]) {
            cout << i << " ";
            break;
        }
    for (int i = 0; i < 1024; ++i)
        if (f[i]) {
            cout << i << " ";
            break;
        }
    return 0;
}