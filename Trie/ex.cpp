#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 100

int main()
{
    ll n,i,j;
    n = 100000001;
    vector<bool>v(n,true);
    v[0] = v[1] = false;
    ll count = 0;
    vector<ll>ans;
    for(i=2;i*i<=n;i++)
    {
        if(v[i] && i%2==1)
        {
            count++;
            if(count%100==1)
              ans.push_back(i);

            for(j=i*i;j<=n;j+=i)
              v[j] = false;
        }
    }

    for(i=0;i<10;i++)
    {
       cout<<ans[i]<<"\n";
    }

    return 0;
}