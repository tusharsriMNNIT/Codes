#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,f=0;
        cin>>n;
        if(n==1 || n==0 || n==-1)
         cout<<"no\n";
        
        for(ll i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                f=1;
                break;
            }
        }
        if(f==1)
         cout<<"no\n";
        else
        {
             cout<<"yes\n";
        }
        
    }
    return 0;
}