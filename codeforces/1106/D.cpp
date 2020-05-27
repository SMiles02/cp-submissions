#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> edges[100001];
bool done[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    priority_queue<int,vector<int>,greater<int>> q;
    done[1]=1;
    q.push(1);
    while (!q.empty())
    {
        v=q.top();
        cout<<v<<" ";
        q.pop();
        for (auto x : edges[v])
            if (!done[x])
            {
                done[x]=1;
                q.push(x);
            }
    }
    return 0;
}