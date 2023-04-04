#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int& i : b)
        cin >> i;
    a[0] = b[0];
    for (int i = 1; i < n - 1; ++i) {
        if (b[i] > b[i - 1])
            a[i + 1] = b[i];
        else {
            a[i] = b[i];
            a[i + 1] = 0;
        }
    }
    for (int i : a)
        cout << i << " ";
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