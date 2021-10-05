#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;
int a[N], p[N];
vector<int> v[2][N];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0,s,x=(1<<25)-1,t,l,r,m;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int k=1;k<1e6;k*=2)
    {
        x^=k;
        s=0;
        for (int i=0;i<N;++i)
        {
            v[0][i].clear();
            v[1][i].clear();
        }
        v[0][0].push_back(0);
        for (int i=1;i<=n;++i)
        {
            p[i]=p[i-1]^a[i]&x;
            v[i&1][p[i]].push_back(i);
            if (a[i]&k)
            {
                if (s==0)
                    s=i;
                t=(int)v[i&1][p[i]].size();
                if (t>1&&v[i&1][p[i]][t-2]>=s-1)
                {
                    l=0;
                    r=t-2;
                    while (l<r)
                    {
                        m=l+(r-l)/2;
                        if (v[i&1][p[i]][m]>=s-1)
                            r=m;
                        else
                            l=m+1;
                    }
                    ans=max(ans,i-v[i&1][p[i]][l]);
                }
            }
            else
                s=0;
        }
    }
    cout<<ans;
    return 0;
}