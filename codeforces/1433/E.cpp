#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fact(int x)
{
    ll ans=1;
    for (int i=1;i<=x;++i)
        ans*=i;
    return ans;
}

ll sq(ll a)
{
    return a*a;
}

ll c(ll n, ll k)
{
    return fact(n)/(fact(k)*fact(n-k));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    cout<<(c(n,n/2)*sq(fact((n/2)-1)))/2;
    return 0;
}