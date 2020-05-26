#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll Floor(ll a[],ll n,ll x)
{
    ll l,r,ans=-1,mid;
    l=0,r=n-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]<=x)
        {
            ans=mid;
            l=mid+1;
        }
        else
         r=mid-1;
    }
    return ans;
}

ll Ceil(ll a[],ll n,ll x)
{
    ll l,r,mid,ans=-1;
    l=0,r=n-1;
    while(l<=r)
    {
       mid = (l+r)/2;
       if(a[mid]>=x)
       {
           ans=mid;
           r=mid-1;
       }
       else
         l=mid+1;
    }
    return ans;
}

int main()
{
    ll n,i,x;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
     cin>>a[i];
    cout<<"Enter the element to be search : ";
    cin>>x;
    ll f = Floor(a,n,x);
    ll c = Ceil(a,n,x);
    cout<<a[f]<<" "<<a[c]<<endl;
    return 0;
}