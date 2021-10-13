//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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

const int N = 4e5+1;
int n, k, a[N];

bool ok(int x)
{
    int cur=0;
    for (int i=x;i<k;++i)
    {
        if (cur>=a[i])
            return 0;
        cur+=n-a[i];
    }
    return 1;
}

void solve()
{
    int l,r,m;
    cin>>n>>k;
    for (int i=0;i<k;++i)
        cin>>a[i];
    sort(a,a+k);
    if (!ok(k-1))
    {
        cout<<"0\n";
        return;
    }
    l=0;r=k-1;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (ok(m))
            r=m;
        else
            l=m+1;
    }
    cout<<k-l<<"\n";
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