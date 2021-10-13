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
int ans[N], eC[N];
vector<int> e[N];

void solve()
{
    int n,k,x,y;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        ans[i]=n+2;
        eC[i]=0;
        e[i].clear();
    }
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    queue<int> q;
    for (int i=1;i<=n;++i)
    {
        eC[i]=sz(e[i]);
        if (eC[i]<=1)
        {
            ans[i]=1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        x=q.front();
        q.pop();
        for (int i : e[x])
            if (ans[x]+1<ans[i]&&--eC[i]<=1)
            {
                ans[i]=ans[x]+1;
                q.push(i);
            }
    }
    x=0;
    for (int i=1;i<=n;++i)
        x+=(ans[i]>k);
    cout<<x<<"\n";
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