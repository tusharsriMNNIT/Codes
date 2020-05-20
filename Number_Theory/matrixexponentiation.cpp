#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define N 101
ll a[N][N],id[N][N];
ll dim;
void mul(ll id[][N], ll a[][N])
{
    ll k,i,j,res[dim+1][dim+1];

    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            res[i][j]=0;
            for(k=0;k<dim;k++)
            {
                ll p = (id[i][k] * a[k][j])%mod;
                res[i][j] = (res[i][j] + p)%mod;
            }
        }
    }

    for(i=0;i<dim;i++)
    {
       for(j=0;j<dim;j++)
       {
           id[i][j] = res[i][j];
       }
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,n;
        cin>>dim>>n;
        for(i=0;i<dim;i++)
        {
            for(j=0;j<dim;j++)
            {
                if(i==j)
                  id[i][j]=1;
                else
                  id[i][j]=0;

                cin>>a[i][j];
            }
        }
        while(n)
        {
            if(n%2)
            {
                mul(id,a);
                n--;
            }
            else
            {
                mul(a,a);
                n/=2;
            }
        }
        for(i=0;i<dim;i++)
        {
            for(j=0;j<dim;j++)
            {
                cout<<id[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}