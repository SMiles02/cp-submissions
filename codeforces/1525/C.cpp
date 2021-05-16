#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct segTree
{
    int n,k;
    vector<int> v;
    segTree(int n) : n(n), v(n*4,0) {}
    void update(int i, int l, int r, int x, int y)
    {
        if (x<l||r<x)
            return;
        v[i]+=y;
        if (l==r)
            return;
        update(i*2+1,l,l+(r-l)/2,x,y);
        update(i*2+2,l+(r-l)/2+1,r,x,y);
    }
    void update(int x, int y)
    {
        update(0,1,n,x,y);
    }
    int findNext(int i, int l, int r, int x)
    {
        if (r<x||v[i]==0)
            return 0;
        if (l==r)
        {
            if (x<=l)
                return l;
            return 0;
        }
        k=findNext(i*2+1,l,l+(r-l)/2,x);
        if (k==0)
            k=findNext(i*2+2,l+(r-l)/2+1,r,x); 
        return k;
    }
    int findNext(int x)
    {
        return findNext(0,1,n,x);
    }
    int findLast(int i, int l, int r, int x)
    {
        if (x<l||v[i]==0)
            return 0;
        if (l==r)
        {
            if (l<=x)
                return l;
            return 0;
        }
        k=findLast(i*2+2,l+(r-l)/2+1,r,x);
        if (k==0)
            k=findLast(i*2+1,l,l+(r-l)/2,x);
        return k;
    }
    int findLast(int x)
    {
        return findLast(0,1,n,x);
    }
};

const int N = 3e5+1;
int m, a[N], ans[N], p[N];
char c[N];
bitset<N> done;
pair<pair<int,char>,int> b[N];

int dt(int x, int y)
{
    if (c[x]=='R'&&c[y]=='L')
        return (a[y]-a[x])/2;
    if (c[x]=='L'&&c[y]=='L')
        return (a[x]+a[y])/2;
    if (c[x]=='R'&&c[y]=='R')
        return (m*2-a[x]-a[y])/2;
    return (m*2+a[x]-a[y])/2;
}

void solve()
{
    int n,x;
    cin>>n>>m;
    segTree s1(n),s2(n);
    vector<int> v,w;
    for (int i=1;i<=n;++i)
    {
        cin>>b[i].first.first;
        b[i].second=i;
        ans[i]=-1;
        done[i]=0;
    }
    for (int i=1;i<=n;++i)
        cin>>b[i].first.second;
    sort(b+1,b+n+1);
    for (int i=1;i<=n;++i)
        a[i]=b[i].first.first,c[i]=b[i].first.second,p[i]=b[i].second;
    for (int i=1;i<=n;++i)
    {
        if (a[i]&1)
        {
            v.push_back(i);
            s1.update(i,1);
        }
        else
        {
            w.push_back(i);
            s2.update(i,1);
        }
    }
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
    for (int i=1;i<sz(v);++i)
        pq.push({dt(v[i-1],v[i]),v[i-1],v[i]});
    for (int i=1;i<sz(w);++i)
        pq.push({dt(w[i-1],w[i]),w[i-1],w[i]});
    array<int,3> t;
    while (!pq.empty())
    {
        t=pq.top();
        pq.pop();
        if (done[t[1]]&&done[t[2]])
            continue;
        if (done[t[2]])
        {
            if (a[t[1]]&1)
                x=s1.findNext(t[2]);
            else
                x=s2.findNext(t[2]);
            if (x!=0)
                pq.push({dt(t[1],x),t[1],x});
            continue;
        }
        if (done[t[1]])
        {
            //cout<<t[1]<<" "<<t[2]<<"\n";
            if (a[t[2]]&1)
                x=s1.findLast(t[1]);
            else
                x=s2.findLast(t[1]);
            if (x!=0)
                pq.push({dt(x,t[2]),x,t[2]});
            continue;
        }
        //cout<<t[1]<<" "<<t[2]<<" "<<t[0]<<"\n";
        ans[p[t[1]]]=ans[p[t[2]]]=t[0];
        done[t[1]]=done[t[2]]=1;
        if (a[t[1]]&1)
        {
            s1.update(t[1],-1);
            s1.update(t[2],-1);
        }
        else
        {
            s2.update(t[1],-1);
            s2.update(t[2],-1);
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
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