#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
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

const int N = 2e6+1;
bitset<N> b;

void solve()
{
    int n,ans=1;
    cin>>n;
    int a[n];
    map<int,int> m;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for (int i=0;i+n/2-1<n;++i)
        if (a[i]==a[i+n/2-1])
        {
            cout<<"-1\n";
            return;
        }
    for (int i=0;i<n;++i)
        for (int j=0;j<i;++j)
            b[a[i]-a[j]]=1;
    for (int i=1;i<N;++i)
        for (int j=i*2;j<N;j+=i)
            b[i]=b[i]|b[j];
    for (int i=2;i<=2e6;++i)
        if (b[i])
        {
            for (int j=0;j<n;++j)
                if (++m[((a[j]%i)+i)%i]==n/2)
                    ans=i;
            m.clear();
        }
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