#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 16) + 3;
int inp[N], ans[N];
bool local = false;

int query(int type, int x, int y) {
    if (local) {
        if (type == 0) {
            return inp[x] & inp[y];
        }
        if (type == 1) {
            return inp[x] | inp[y];
        }
        if (type == 2) {
            return inp[x] ^ inp[y];
        }
    }
    if (type == 0) {
        cout << "AND";
    }
    if (type == 1) {
        cout << "OR";
    }
    if (type == 2) {
        cout << "XOR";
    }
    cout << " " << x << " " << y << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b, c, d, e, f, x, y, z;
    cin >> n;
    if (local) {
        for (int i = 1; i <= n; ++i) {
            cin >> inp[i];
        }
    }
    a = query(0, 1, 2);
    b = query(2, 1, 2);
    x = b + a * 2;
    c = query(0, 1, 3);
    d = query(2, 1, 3);
    y = d + c * 2;
    e = query(0, 2, 3);
    f = b ^ d;
    z = f + e * 2;
    ans[1] = (x + y - z) / 2;
    ans[2] = x - ans[1];
    ans[3] = y - ans[1];
    for (int i = 4; i <= n; ++i) {
        int tmp = query(2, 1, i);
        ans[i] = tmp ^ ans[1];
    }
    cout << "!";
    for (int i = 1; i <= n; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}