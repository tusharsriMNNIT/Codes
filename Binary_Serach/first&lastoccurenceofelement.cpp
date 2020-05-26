#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll first(ll a[],ll n,ll x)
{
    ll mid,ans=-1,l=0,r=n-1;
    while(l<=r)
    { 
       mid = (l+r)/2;
       if(a[mid]==x)
       {
           ans=mid;
           r=mid-1;
       }
       else if(a[mid]>x)
          r=mid-1;
       else
          l = mid+1;
    }
    return ans;
}

ll last(ll a[],ll n,ll x)
{
    ll mid,ans=-1,l=0,r=n-1;
    while(l<=r)
    { 
       mid = (l+r)/2;
       if(a[mid]==x)
       {
           ans=mid;
           l=mid+1;
       }
       else if(a[mid]>x)
          r=mid-1;
       else
          l = mid+1;
    }
    return ans;
}

ll lower(ll a[],ll n,ll x)
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
        {
            l=mid+1;
        }
    }
    return ans;
}

ll upper(ll a[],ll n,ll x)
{
    ll l=0,r=n-1,mid,ans=-1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(a[mid]<=x)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}

int main()
{
    ll n,x,i;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
     cin>>a[i];
    cout<<"Enter element you have to search : ";
    cin>>x;
    ll l = first(a,n,x);
    ll r = last(a,n,x);

    if(l==-1 || r==-1 || (a[l]!=x) || a[r]!=x)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<"Found at : ";
        cout<<l<<" "<<r<<endl;
    }
    
    return 0;
}