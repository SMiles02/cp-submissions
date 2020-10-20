#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define pli pair<ll,int>
#define f first
#define s second
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

const int maxn = 1002, INF = 1e9;
int n,m,k,dist[2001][maxn],d[maxn][maxn],x,y;
vector<pii> edges[maxn];

void dijkstra(int id, int src)
{
    priority_queue<pii,vector<pii>,greater<pii>> q;
    for (int i=1;i<=n;++i)
        dist[id][i]=INF;
    q.push({0,src});
    dist[id][src]=0;
    while (!q.empty())
    {
        y=q.top().f;
        x=q.top().s;
        q.pop();
        if (dist[id][x]<y)
            continue;
        for (pii i : edges[x])
            if (y+i.s<dist[id][i.f])
            {
                dist[id][i.f]=y+i.s;
                q.push({dist[id][i.f],i.f});
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    int a,b,c,r[k][2];
    vector<pii> allEdges;
    while (m--)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
        allEdges.push_back({a,b});
    }
    for (int i=1;i<=n;++i)
        dijkstra(i,i);
    ll ans=0,cur;
    for (int i=0;i<k;++i)
    {
        cin>>r[i][0]>>r[i][1];
        ans+=dist[r[i][0]][r[i][1]];
    }
    for (pii i : allEdges)
    {
        edges[i.f].push_back({i.s,0});
        dijkstra(n+1,i.f);
        cur=0;
        for (int j=0;j<k;++j)
            cur+=min(dist[r[j][0]][r[j][1]],dist[n+1][r[j][0]]+dist[n+1][r[j][1]]);
        ans=min(ans,cur);
        edges[i.f].pop_back();
    }
    cout<<ans;
    return 0;
}