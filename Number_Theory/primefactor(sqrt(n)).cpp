#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n,i;
    cin>>n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll cnt = 0;
            while(n%i==0)
            {
                cnt++;
                n/=i;
            }
            cout<<i<<" "<<cnt<<endl;
        }
    }
    if(n>1)
     cout<<n<<" "<<"1"<<endl;
    return 0;
}