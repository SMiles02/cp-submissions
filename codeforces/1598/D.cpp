//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll f(ll x)
{
    return (x*(x-1))/2;
}

void solve()
{
    int n;
    cin>>n;
    int a[n][2];
    map<int,int> c,d;
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        ++c[a[i][0]];
        ++d[a[i][1]];
    }
    ll ans=(1LL*n*(n-1)*(n-2))/6;
    for (int i=0;i<n;++i)
        ans-=1LL*(c[a[i][0]]-1)*(d[a[i][1]]-1);
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}