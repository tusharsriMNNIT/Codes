// Allocate Minimum Number of Pages
// Given array is unsorted
// Arr[i] denotes the number of pages in ith book
// Coditions :- 1-) One book can be allocated to only one student
// 2-) At least one book should be given to each student
// 3-) Books should be allocated in continuous fashion
// Example : 10 20 30 40
// Some combinations are (10,90) , (30,70) , (60,40) answer would be 60.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

bool isValid(ll a[],ll n,ll k, ll m)
{
    ll i,student = 1,sum=0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>m)
        {
            student++;
            sum=a[i];
        }
        if(student>k)
         return false;
    }
    return true;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,r=0,l=0,k,res=-1,mid;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
        {
           cin>>a[i];
           r+=a[i];
           l=max(l,a[i]);
        }
        cin>>k;
        if(n<k)
        {
            cout<<"-1\n";
            continue;
        }
        while(l<=r)
        {
            mid = (l+r)/2;
            if(isValid(a,n,k,mid))
            {
                res = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}