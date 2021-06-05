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

bitset<4> a[100000];
bitset<2<<5> dp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x;
    bool ok;
    cin>>n>>k;
    for (int i=0;i<n;++i)
        for (int j=0;j<k;++j)
        {
            cin>>x;
            a[i][j]=x;
        }
    dp[0]=1;
    for (int i=0;i<n;++i)
        for(int j=1;j<(1<<k);++j)
        {
            ok=1;
            for (int l=0;l<k;++l)
                if (((1<<l)&j)&&a[i][l]==1)
                    ok=0;
            if (ok)
            {
                //cout<<i<<" "<<j<<"\n";
                dp[j]=1;
                if (dp[(1<<k)-j-1])
                {
                    //cout<<j<<"\n";
                    cout<<"YES";
                    return 0;
                }
            }
        }
    cout<<"NO";
    return 0;
}