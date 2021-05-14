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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,l,r,mid;
    cin>>n>>m>>k;
    if (n+m-2<k)
    {
        cout<<-1;
        return 0;
    }
    vector<array<int,2>> v,w;
    for (int i=1;i<=n;++i)
    {
        v.push_back({n/i-1,n/(n/i)});
        i=n/(n/i);
    }
    for (int i=1;i<=m;++i)
    {
        w.push_back({m/i-1,m/(m/i)});
        i=m/(m/i);
    }
    ll ans=1;
    for (auto i : v)
    {
        if (i[0]+m-1<k)
            continue;
        l=0;r=sz(w)-1;
        while (l<r)
        {
            mid=l+(r-l)/2+1;
            if (i[0]+w[mid][0]<k)
                r=mid-1;
            else
                l=mid;
        }
        ans=max(ans,1LL*i[1]*w[l][1]);
    }
    cout<<ans;
    return 0;
}