#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,mini=101,maxi=-1,x,y,k;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (k<=mini)
        {
            mini=k;
            x=i;
        }
        if (k>maxi)
        {
            maxi=k;
            y=i;
        }
    }
    if (x<y)
        cout<<y+n-2-x;
    else
        cout<<y+(n-1-x);
    return 0;
}