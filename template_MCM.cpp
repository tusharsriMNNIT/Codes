#include<bits/stdc++.h>
using namespace std;

int solve(int a[],int i,int j)
{
    if(i>j)
     return 0;
    
    for(int k=i;k<=j;k++)
    {
        int temp_ans = solve(a,i,k) + solve(a,k+1,j);

        int ans=max(ans,temp_ans);
    }
    return ans;
}