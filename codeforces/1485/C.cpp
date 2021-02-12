#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve()
{
    int x,y,l=0,r,m,d,v;
    cin>>x>>y;
    r=min(y,31623);
    while (l^r)
    {
        m=l+(r-l)/2+1;
        if ((m+1)*(m-1)<=x)
            l=m;
        else
            r=m-1;
    }
    ll ans=(l*(l-1))/2;
    d=l;
    while (d<y)
    {
        l=d+1;r=y;
        v=x/(l+1);
        while (l<r)
        {
            m=l+(r-l)/2+1;
            if (x/(m+1)==v)
                l=m;
            else
                r=m-1;
        }
        ans+=1LL*(r-d)*v;
        d=l;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    /**
    for (int j=1;j<=100;++j)
        for (int i=1;i<=100;++i)
            if (i/j==i%j)
                cout<<i<<" "<<j<<"\n";
    **/
    while (n--)
        solve();
    return 0;
}