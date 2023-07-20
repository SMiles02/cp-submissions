#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t, u;
    cin >> s;
    int n = s.size(), cur = 0;
    vector<int> v(26);
    for (auto i : s) {
        ++v[i - 'a'];
    }
    while (u.size() < n) {
        int smallest = 26;
        for (int i = 25; i >= 0; --i) {
            if (v[i] > 0) {
                smallest = i;
            }
        }
        if (!t.empty() && (t.back() - 'a') <= smallest) {
            u += t.back();
            t.pop_back();
        }
        else {
            while (s[cur] - 'a' != smallest) {
                t += s[cur];
                --v[s[cur] - 'a'];
                ++cur;
            }
            u += s[cur];
            --v[s[cur] - 'a'];
            ++cur;
        }
    }
    cout << u;
    return 0;
}