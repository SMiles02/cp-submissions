#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll u,v;
    cin>>u>>v;
    vector<int> x,y;
    for (int i=0;i<31;++i)
    {
        if ((1LL<<i)&u)
            x.push_back(i);
        if ((1LL<<i)&v)
            y.push_back(i);
    }
    if (u>v||__builtin_popcountll(u)<__builtin_popcountll(v))
    {
        cout<<"NO\n";
        return;
    }
    for (int i=0;i<sz(y);++i)
        if (x[i]>y[i])
        {
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}