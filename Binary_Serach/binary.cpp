#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll binary(ll a[],ll n,ll x)
{
   ll ans=-1,mid,l=0,r=n-1;
   while(l<=r)
   {
       //mid = (l+r)/2;
       mid = l + (r-l)/2;
       if(a[mid]==x)
        return mid;
       else if(a[mid]>x)
        r = mid-1;
       else
        l = mid+1;
   }
   return ans;
}

int main()
{
    ll n,i,x;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter element whose index you have to search : ";
    cin>>x;
    ll ans = binary(a,n,x);
    cout<<ans<<endl;
    return 0;
}