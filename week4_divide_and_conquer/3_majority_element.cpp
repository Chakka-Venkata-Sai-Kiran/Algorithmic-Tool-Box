#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,key,i;
    unordered_map<ll,ll> dict;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>key;
        if(dict.find(key)==dict.end())
            dict.insert(make_pair(key,0));
        else
        {
            auto it=dict.find(key);
            it->second++;
        }
    }
    i=0;
    for(auto it=dict.begin();it!=dict.end();it++)
    {
        if(it->second>=n/2)
        {
            cout<<1;
            i=1;
            break;
        }
    }
    if(i==0)
        cout<<0;
    return 0;
}
