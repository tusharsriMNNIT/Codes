// In this you have to find how many times sorted array is rotated
// Number of rotations = Index of minimum element

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll find(ll a[],ll n)
{
    ll l=0,r=n-1,mid,ans=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        ll prev = (mid-1+n)%n;
        ll next = (mid+1)%n;
        if(a[next]>=a[mid] && a[prev]>a[mid])
         {
            return mid;
         }
        else if(a[r]<a[mid])
         l=mid+1;
        else if(a[mid]<a[r])
         r=mid-1;
        else
         r--;
    }
    return 0;
}

int main()
{
    ll n,i,x;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
     cin>>a[i];
    
    
    ll ans = find(a,n);
    cout<<ans<<endl;
    
    return 0;
}