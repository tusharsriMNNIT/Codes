#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define N 5
ll arr[N][N],idn[N][N];

void mul(ll a[][N],ll b[][N])
{
    ll res[3][3],i,j,k;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            res[i][j]=0;
            for(k=0;k<2;k++)
            {
                ll p = (a[i][k] * b[k][j])%mod;
                res[i][j] = (res[i][j] + p)%mod;
            }
        }
    }

    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            a[i][j]=res[i][j];
        }
    }
}
ll solve(ll a,ll b,ll n)
{ 
    ll i,j;
    
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
           if(i==j)
            idn[i][j]=1;
           else
            idn[i][j]=0;   
        }
    }
    arr[0][0]=0;
    arr[1][0]=1;
    arr[0][1]=1;
    arr[1][1]=1;

    while(n>0)
    {
        //cout<<n<<endl;
        if(n%2)
         mul(idn,arr),n--;
        else
         mul(arr,arr),n/=2;
    }
    //cout<<"hello\n";
    ll ans = ( (a*idn[0][0])%mod + (b*idn[1][0])%mod )%mod;
    return ans;
}


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        memset(idn,0,sizeof(idn));
        ll a,b,n;
        cin>>a>>b>>n;
        ll ans = solve(a,b,n);
        cout<<ans<<endl;
    }
    return 0;
}