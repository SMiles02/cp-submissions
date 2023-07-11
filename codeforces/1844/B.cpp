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

const int N = 2e5 + 10;
bitset<N> sieve;

void solve() {
    int n;
    cin >> n;
    deque<int> d;
    if (n == 1) {
        d = {1};
    }
    else if (n == 2) {
        d = {1, 2};
    }
    else if (n == 3) {
        d = {3, 1, 2};
    }
    else if (n == 4) {
        d = {2, 1, 4, 3};
    }
    else {
        int l = 0, r = 0;
        d = {2, 1};
        for (int i = 6; i <= n; ++i) {
            if (l == r + 1) {
                d.push_back(i);
                ++r;
            }
            else {
                d.push_front(i);
                ++l;
            }
        }
        d.push_front(5);
        d.push_back(4);
        d.push_back(3);
    }
    for (int i : d) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; ++i) {
        for (int j = i * 2; j < N; j += i) {
            sieve[j] = 1;
        }
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}