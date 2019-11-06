#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
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
    int k,n;
    string s,t;
    vector<int> v;
    cin>>k;
    while (k--)
    {
        cin>>n;
        cin>>s;
        cin>>t;
        for (int i=0;i<n;++i)
        {
            if (s[i]!=t[i])
            {
                v.push_back(i);
            }
        }
        if (v.size()==2)
        {
            if (s[v[0]]==s[v[1]]&&t[v[1]]==t[v[0]])
            {
                cout<<"Yes";
            }
            else
            {
                cout<<"No";
            }
        }
        else if (v.size()==0)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
        cout<<"\n";
        v.clear();
    }
    return 0;
}