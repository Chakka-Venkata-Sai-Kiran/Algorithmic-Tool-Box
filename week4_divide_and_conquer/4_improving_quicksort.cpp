#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,n;
    cin>>n;
    vector<ll> v(n,0);
    for(i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}
