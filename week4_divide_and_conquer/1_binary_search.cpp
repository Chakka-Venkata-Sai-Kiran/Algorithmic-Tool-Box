#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k,i,first,last,flag;
    ll key;
    cin>>n;
    vector<ll> arr1,arr2;
    for(i=0;i<n;i++)
    {
        cin>>key;
        arr1.push_back(key);
    }
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>key;
        arr2.push_back(key);
    }
    for(i=0;i<k;i++)
    {
        first=0;
        last=n-1;
        flag=0;
        key=arr2[i];
        while(first<=last)
        {
            ll mid=first+(last-first)/2;
            if(arr1[mid]==key)
            {
                cout<<mid<<" ";
                flag=1;
                break;
            }
            else if(arr1[mid]<key)
                first=mid+1;
            else
                last=mid-1;
        }
        if(flag==0)
            cout<<-1<<" ";
    }
    return 0;
}
