#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    if (n>60)
    {
        cout<<1;
        return 0;
    }
    int x[n+1],ans=n;
    x[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>x[i];
        x[i]^=x[i-1];
    }
    for (int i=1;i<=n;++i)
        for (int j=i;j<=n;++j)
            for (int k=j+1;k<=n;++k)
                for (int l=k;l<=n;++l)
                    if ((x[j]^x[i-1])>(x[l]^x[k-1]))
                        ans=min(ans,j+l-i-k);
    if (ans==n)
        ans=-1;
    cout<<ans;
    return 0;
}