#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2;
set<int> e[N];
vector<int> ans;

void selfdestruct(int c, int p) {
    cout << c << "\n";
    while (!e[c].empty()) {
        int x = *e[c].begin();
        e[c].erase(x);
        e[x].erase(c);
        if (x != p) {
            selfdestruct(x, c);
        }
    }
}

void dfs(int c, int p) {
    vector<int> temp_edges;
    for (int i : e[c]) {
        if (i != p) {
            temp_edges.push_back(i);
        }
    }
    for (int i : temp_edges) {
        dfs(i, c);
    }
    if (e[c].size() % 2 == 0) {
        selfdestruct(c, p);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1, p; i <= n; ++i) {
        cin >> p;
        if (p != 0) {
            e[p].insert(i);
            e[i].insert(p);
        }
    }
    cout << "YES\n";
    dfs(1, 0);
    for (int i : ans) {
        cout << i << "\n";
    }
    return 0;
}