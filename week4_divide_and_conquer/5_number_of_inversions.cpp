#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll ans=0;
void count(ll low,ll mid,ll high)
{
    ll i=low,j=mid+1;
    vector<ll> temp;
    while(i<=mid && j<=high)
    {
        if(v[i]>v[j])
        {
            temp.push_back(v[i]);
            ans+=high-j+1;
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while(j<=high)
    {
        temp.push_back(v[j]);
        j++;
    }
    i=0;
    j=low;
    while(j<=high)
    v[j++]=temp[i++];
}
void inversions(ll low,ll high)
{
    if(low>=high)
        return;
    ll mid=(low+high)/2;
    inversions(low,mid);
    inversions(mid+1,high);
    count(low,mid,high);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,n,key;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>key;
        v.push_back(key);
    }
    inversions(0,n-1);
    cout<<ans;
    return 0;
}
