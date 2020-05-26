// Order-agnostic means it is given that array is sorted but in ascending or descending it is not given.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll asc_binary_serach(ll a[],ll n,ll x)
{
    ll mid,l,r,ans=-1;
    l=0,r=n-1;
    while(l<=r)
    {
        mid = l+(r-l)/2;
        if(a[mid]==x)
         return mid;
        else if(a[mid]>x)
         r = mid-1;
        else
         l = mid+1;
    }
    return ans;
}

ll desc_binary_seach(ll a[],ll n,ll x)
{
    ll mid,l,r,ans=-1;
    l=0,r=n-1;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(a[mid]==x)
         return mid;
        else if(a[mid]>x)
         l = mid+1;
        else
         r = mid-1;/* code */
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
    
    cout<<"Enter element you have to search : ";
    cin>>x;
    if(n==1 && a[0]==x)
    { 
        cout<<"0\n";
    }
    else if(a[0]>a[n-1])
    {
       ll ans = desc_binary_seach(a,n,x);
       cout<<ans<<endl;
    }
    else
    {
        ll ans = asc_binary_serach(a,n,x);
        cout<<ans<<endl;
    }
    return 0;
}