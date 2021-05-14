#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define pli pair<ll,int>
#define f first
#define s second
using namespace std;

const int maxn = 2e5+7;
const ll INF = 1e18;
int n,m,k,x,ans,train[maxn];
vector<pii> edges[maxn];
ll dist[maxn],y;
bitset<maxn> inUse;

void dijkstra(int src)
{
    priority_queue<pli,vector<pli>,greater<pli>> q;
    for (int i=1;i<=n;++i)
    {
        if (train[i])
        {
            inUse[i]=1;
            dist[i]=train[i];
            q.push({dist[i],i});
        }
        else
            dist[i]=INF;
    }
    q.push({0,src});
    dist[src]=0;
    while (!q.empty())
    {
        y=q.top().f;
        x=q.top().s;
        q.pop();
        if (dist[x]<y)
            continue;
        if (train[x]&&inUse[x])
            --ans;
        for (pii i : edges[x])
        {
            if (y+i.s<=dist[i.f])
                inUse[i.f]=0;
            if (y+i.s<dist[i.f])
            {
                dist[i.f]=y+i.s;
                q.push({dist[i.f],i.f});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    int a,b,c;
    while (m--)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    ans=k;
    while (k--)
    {
        cin>>a>>b;
        if (train[a])
            train[a]=min(train[a],b);
        else
            train[a]=b;
    }
    dijkstra(1);
    cout<<ans;
    return 0;
}