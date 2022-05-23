#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    n=n%60;
    if(n==0 || n==1)
    {
        cout<<n;
        return 0;
    }    
    ll a=0,b=1;
    for(ll i=2;i<=n;i++)
    {
        ll c=a;
        a=b;
        b=(c+b)%10;
    }
    cout<<b;
    return 0;
}
