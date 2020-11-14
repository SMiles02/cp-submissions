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

ll f[40002],g[40002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,c=0;
    cin>>n>>m>>k;
    int a[n],b[m];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        if (a[i])
            ++c;
        else
            c=0;
        ++f[c];
    }
    c=0;
    for (int i=0;i<m;++i)
    {
        cin>>b[i];
        if (b[i])
            ++c;
        else
            c=0;
        ++g[c];
    }
    for (int i=40000;i;--i)
    {
        f[i]+=f[i+1];
        g[i]+=g[i+1];
    }
    ll ans=0;
    for (ll i=1;i<=40000;++i)
        if (k%i==0)
            if (k/i<=40000)
            {
                ans+=(f[i]*g[k/i])+(g[i]*f[k/i]);
            }
    cout<<ans/2;
    return 0;
}