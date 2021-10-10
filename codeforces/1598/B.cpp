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

int a[1000][5];

void solve()
{
    int n,k;
    cin>>n;
    for (int i=0;i<n;++i)
        for (int j=0;j<5;++j)
            cin>>a[i][j];
    for (int i=0;i<5;++i)
        for (int j=0;j<5;++j)
            if (i!=j)
            {
                int x=0,y=0,z=0,t;
                for (int k=0;k<n;++k)
                {
                    if (a[k][i]==1&&a[k][j]==1)
                        ++z;
                    else if (a[k][i])
                        ++x;
                    else if (a[k][j])
                        ++y;
                }
                if (x<=n/2&&y<=n/2&&x+y+z==n)
                {
                    cout<<"YES\n";
                    return;
                }
            }
    cout<<"NO\n";
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