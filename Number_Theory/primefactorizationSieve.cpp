#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define max 1000004
ll leastPrime[max];

void leastPrimeCalculate()
{
    ll i,j;
    memset(leastPrime,-1,sizeof(leastPrime));
    leastPrime[0]=0;
    leastPrime[1]=1;
    for(i=2;i*i<=max;i++)
    {
       if(leastPrime[i]==-1)
       {
           leastPrime[i]=i;
           for(j=i*i;j<max;j+=i)
           {
               if(leastPrime[j]==-1)
               {
                   leastPrime[j]=i;
               }
           }
       }
    }
}

int main()
{
    leastPrimeCalculate();
    for(ll i=1;i<=10;i++)
     cout<<leastPrime[i]<<" ";
    cout<<endl;
    return 0;
}