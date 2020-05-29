#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
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

ll d1[100001+5];
ll d2[100001+5];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,k,c,d,cur=0;
    cin>>n>>m>>k;
    ll a[n+5];
    ll x[m+5][3];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i)
        cin>>x[i][0]>>x[i][1]>>x[i][2];
    for (int i=1;i<=k;++i)
    {
        cin>>c>>d;
        ++d2[c];
        --d2[d+1];
    }
    for (int i=1;i<=m;++i)
    {
        d1[x[i][0]]+=((cur+d2[i])*x[i][2]);
        d1[x[i][1]+1]-=((cur+d2[i])*x[i][2]);
        cur+=d2[i];
    }
    cur=0;
    for (int i=1;i<=n;++i)
    {
        cout<<cur+d1[i]+a[i]<<" ";
        cur+=d1[i];
    }
    return 0;
}