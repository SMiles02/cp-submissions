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
    int n,m;
    cin>>n>>m;
    char c;
    m=min(m,n+4);
    int a[n+2],b[n+2];
    for (int i=1;i<=n;++i)
    {
        cin>>c;
        a[i]=c-'0';
    }
    a[0]=a[n+1]=0;
    while (m--)
    {
        for (int i=0;i<=n+1;++i)
            b[i]=a[i];
        for (int i=1;i<=n;++i)
            if (a[i]==0&&(a[i-1]^a[i+1])==1)
                b[i]=1;
        for (int i=1;i<=n;++i)
            a[i]=b[i];
    }
    for (int i=1;i<=n;++i)
        cout<<a[i];
    cout<<"\n";
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