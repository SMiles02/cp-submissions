#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    ll s=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(0);
    while (n--)
    {
        cin>>k;
        if (s+k>=0)
        {
            s+=k;
            pq.push(k);
        }
        else if (k>pq.top())
        {
            s-=pq.top();
            pq.pop();
            s+=k;
            pq.push(k);
        }
    }
    cout<<sz(pq)-1;
    return 0;
}