#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll base,exponent;
    cin>>base>>exponent;
    ll ans=1;
    while(exponent)
    {
        if(exponent%2)
        {
            ans*=base;
            exponent--;
        }
        else
        {
            base *=base;
            exponent/=2;   
        }
    }
    cout<<ans<<endl;
    return 0;
}