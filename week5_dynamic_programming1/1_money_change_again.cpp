#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mincoins(vector<ll> v,ll n)
{
    if(v[n]!=-1)
        return v[n];
    return 1+min( mincoins(v,n-1),min( mincoins(v,n-3),mincoins(v,n-4) ));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,i;
    cin>>n;
    if(n<=2)
    {
        cout<<n;    return 0;
    }
    else if(n<=4)
    {
        cout<<1;    return 0;
    }
    vector<ll> v(n+1,-1);
    v[0]=0;
    v[1]=1;
    v[2]=2;
    v[3]=v[4]=1;
    for(i=5;i<=n;i++)
        v[i]=mincoins(v,i);
    cout<<v[n];
    return 0;
}
