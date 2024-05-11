#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, l, r;
    ll k, ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    l = 0;
    r = n - 1;
    while (l < r) {
        if (a[l + 1] == a[l]) {
            ++l;
            continue;
        }
        if (a[r - 1] == a[r]) {
            --r;
            continue;
        }
        if (min(l + 1, n - r) > k) {
            break;
        }
        if (l + 1 < n - r) {
            ll tmp = min(k / (l + 1), (ll)a[l + 1] - a[l]);
            k -= tmp * (l + 1);
            a[l] += tmp;
        }
        else {
            ll tmp = min(k / (n - r), (ll)a[r] - a[r - 1]);
            k -= tmp * (n - r);
            a[r] -= tmp;
        }
    }
    cout << a[r] - a[l] << "\n";
    return 0;
}