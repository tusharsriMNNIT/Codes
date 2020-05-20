#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define max 1000004
bool isPrime[max];

void sieve()
{
    ll i,j;
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    for(i=2;i*i<=max;i++)
    {
        if(isPrime[i])
        {
            for(j=i*i;j<max;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
}

int main()
{
    sieve();
    ll n;
    cout<<"Enter number to check whether it is prime or not : ";
    cin>>n;
    cout<<isPrime[n]<<endl;
    return 0;
}