//Not my code
//Trying to debug https://codeforces.com/contest/1342/submission/117835730

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, q;
        cin >> a >> b >> q;
        vector<int> ab(a*b);
        for(int i = 0; i < a*b; i++){
            if(i%a%b != i%b%a) ab[i] = 1;
        }
        for(int i = 1; i < a*b; i++) ab[i] += ab[i - 1];
        while(q--){
            ll l, r;
            cin >> l >> r;
            cout << 1LL*(r/(a*b))*ab[a*b-1] + ab[r%(a*b)] - 1LL*((l-1)/(a*b))*ab[a*b-1] - ab[(l-1)%(a*b)] << " ";
        }
        cout << endl;
    }
    return 0;
}