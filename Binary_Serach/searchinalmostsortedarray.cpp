#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll find(ll a[],ll n,ll x)
{
    ll l,r,mid,ans=-1;
    l=0,r=n-1;
    while(l<=r)
    {
       mid = (l+r)/2;
       if(a[mid]==x)
        return mid;
       else if(mid-1>=l && a[mid-1]==x)
        return mid-1;
       else if(mid+1>=r && a[mid+1]==x)
        return mid+1;
       
       if(a[mid]>x)
        r=mid-2;
       else
        l=mid+2;
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
    ll ans = find(a,n,x);
    cout<<ans<<endl;
    return 0;
}