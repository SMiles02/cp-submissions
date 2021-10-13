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

int check(string s, char a, char b)
{
    int rt=0;
    bool fd=0;
    for (int i=sz(s)-1;i>=0;--i)
    {
        if (fd)
        {
            if (s[i]==a)
                return rt;
            ++rt;
        }
        else
        {
            if (s[i]==b)
                fd=1;
            else
                ++rt;
        }
    }
    return 100;
}

void solve()
{
    int ans=100;
    string s;
    cin>>s;
    ans=min(ans,check(s,'0','0'));
    ans=min(ans,check(s,'2','5'));
    ans=min(ans,check(s,'5','0'));
    ans=min(ans,check(s,'7','5'));
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