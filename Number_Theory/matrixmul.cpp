#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll j,n,i,k;
    cin>>n;
    ll a[n][n],b[n][n],res[n][n];
    cout<<"Enter first matrix : ";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<"Enter the second matrix : ";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>b[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            res[i][j]=0;
            for(k=0;k<n;k++)
            {
                res[i][j]+=(a[i][k] * b[k][j]);
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}