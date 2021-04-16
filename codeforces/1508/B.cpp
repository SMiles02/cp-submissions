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
    int n;
    ll k;
    cin>>n>>k;
    if (n<=62&&(1LL<<(n-1))<k)
    {
        cout<<"-1\n";
        return;
    }
    --k;
    vector<int> v(n+1);
    iota(v.begin(), v.end(), 0);
    for (int i=max(n-62,1);i<=n;++i)
    {
        for (int j=i;j<=n;++j)
        {
            if (j==n)
            {
                for (int l=i;l<=n;++l)
                    v[l]=i+j-l;
                i=n;
            }
            else if ((1LL<<(n-j-1))<=k)
                k-=(1LL<<(n-j-1));
            else
            {
                for (int l=i;l<=j;++l)
                    v[l]=i+j-l;
                i=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;++i)
        cout<<v[i]<<" ";
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