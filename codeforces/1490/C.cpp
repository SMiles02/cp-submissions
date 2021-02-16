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

set<ll> cubes;

void solve()
{
    ll n;
    cin>>n;
    for (ll i : cubes)
    {
        if (cubes.find(n-i)!=cubes.end())
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
    for (int i=1;i<10001;++i)
        cubes.insert(1LL*i*i*i);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}