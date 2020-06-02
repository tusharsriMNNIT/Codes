//Array is unsorted and a[i]!=a[i+1] and peak element satisfies the condition : 
// suppose i peak element then a[i-1]<a[i]>a[i+1].
// 5 10 20 15

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll peak(ll a[],ll l,ll r)
{
    ll mid,ans=-1;
    ll n = r+1;
    while(l<=r)
    {
        mid = (l+(r-l)/2);
        if(mid-1>=0 && mid+1<=n-1)
        {
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
            {
                ans=mid;
                break;
            }
            else if(a[mid-1]>a[mid])
             r=mid-1;
            else 
             l=mid+1;
        }
        else if(mid==0)
        {
            if(a[mid]>a[mid+1])
            ans=mid;
            else
            ans=1;
            break;
        }
        else if(mid==n-1)
        {
            if(a[mid]>a[mid-1])
            ans=mid;
            else
            ans=mid-1;
            break;
        }
    }
    return ans;
}


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,n;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
          cin>>a[i];
        
        ll ans = peak(a,0,n-1);
        cout<<a[ans]<<endl;
    }
    return 0;
}