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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<int>> a(n, vector<int>(m, h));
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < n; ++j) {
            a[j][i] = min(a[j][i], x);
        }
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < m; ++j) {
            a[i][j] = min(a[i][j], x);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if (x == 0) {
                a[i][j] = 0;
            }
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}