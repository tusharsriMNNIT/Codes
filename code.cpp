#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n,i,j,ans=0;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
     cin>>a[i];
    
    for(i=1;i<n;i++)
    {
       if(a[i]>=a[i-1])
        continue;
       else
       {
           ans+=abs(a[i]-a[i-1]);
           a[i]=a[i-1];
       }
    }
    cout<<ans<<endl;
    return 0;
}