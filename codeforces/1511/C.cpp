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

int id[51];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        if (!id[x])
            id[x]=i;
    }
    while (q--)
    {
        cin>>x;
        cout<<id[x]<<" ";
        for (int i=1;i<=50;++i)
            if (id[i]<id[x])
                ++id[i];
        id[x]=1;
    }
    return 0;
}