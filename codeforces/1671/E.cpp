#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = (1 << 18);
int dp[N];
string t[N];

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}
 
int mul(int a, int b) { return (1LL*a*b)%MOD; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    n = (1 << n) - 1;
    string s;
    cin >> s;
    s = "?" + s;
    for (int i = n; i >= 1; --i) {
        t[i] = s[i];
        if (i * 2 > n)
            dp[i] = 1;
        else {
            if (t[i * 2] == t[i * 2 + 1])
                dp[i] = mul(dp[i * 2], dp[i * 2 + 1]);
            else {
                if (t[i * 2] < t[i * 2 + 1])
                    swap(t[i * 2], t[i * 2 + 1]);
                dp[i] = mul(2, mul(dp[i * 2], dp[i * 2 + 1]));
            }
            t[i] += t[i * 2];
            t[i] += t[i * 2 + 1];
        }
    }
    cout << dp[1];
    return 0;
}