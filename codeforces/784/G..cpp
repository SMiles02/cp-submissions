#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, cnt = 0;
    char c = '+';
    string base = "++++++++++++++++++++++++++++++++++++++++++++++++";
    while (true) {
        if (c != '?') {
            cin >> n;
            if (c == '+') {
                cnt += n;
            }
            else {
                cnt -= n;
            }
            c = '?';
        }
        else {
            cin >> c;
            if (c != '+' && c != '-') {
                break;
            }
        }
    }
    vector<int> v;
    while (v.empty() || cnt > 0) {
        v.push_back(cnt % 10);
        cnt /= 10;
    }
    while (!v.empty()) {
        cout << base << string(v.back(), '+') << ".>\n";
        v.pop_back();
    }
    return 0;
}