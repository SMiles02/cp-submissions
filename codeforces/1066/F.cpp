#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<ll,ll>
using namespace std;

map<ll,bool> done;
map<ll,pii> l;
map<ll,pii> r;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

void pri(pair<int,int> p)
{
    cout<<"p: "<<p.first<<" "<<p.second<<"\n";
}

ll dist(pair<ll,ll> p, pair<ll,ll> q)
{
    return abs(p.first-q.first)+abs(p.second-q.second);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,x,y,z;
    cin>>n;
    vector<ll> v={0};
    for (ll i=0;i<n;++i)
    {
        cin>>x>>y;
        z=max(x,y);
        if (!done[z])
        {
            done[z]=1;
            l[z]={x,y};
            r[z]={x,y};
            v.push_back(z);
        }
        else
        {
            if ((y>l[z].second)||(y==l[z].second&&x<l[z].first))
                l[z]={x,y};
            if ((x>r[z].first)||(x==r[z].first&&y<r[z].second))
                r[z]={x,y};
        }
    }
    z=sz(v);
    ll dp[z][2];
    sort(v.begin(), v.end());
    dp[0][0]=0;
    dp[0][1]=0;
    for (ll i=1;i<z;++i)
    {
        dp[i][0]=dist(l[v[i]],r[v[i]])+min(dp[i-1][0]+dist(l[v[i-1]],r[v[i]]),dp[i-1][1]+dist(r[v[i-1]],r[v[i]]));
        dp[i][1]=dist(l[v[i]],r[v[i]])+min(dp[i-1][0]+dist(l[v[i-1]],l[v[i]]),dp[i-1][1]+dist(r[v[i-1]],l[v[i]]));
        //cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }
    if (dp[z-1][0]<dp[z-1][1])
        cout<<dp[z-1][0];
    else
        cout<<dp[z-1][1];
    return 0;
}