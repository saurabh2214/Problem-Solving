#include<bits/stdc++.h>
using namespace std;
/*             memoization              */
int sqrRec(int n,vector<int> &dp)
{
    if(n<=0)
    {
        return 0;
    }
    if(dp[n]!=1e9)
    {
        return dp[n];
    }
    int k=1e9;
    for(int i=1;i*i<=n;i++)
    {
        k=min(k,sqrRec(n-i*i,dp)+1);
    }
    return dp[n]=k;
}
int numSquares(int n) {
    vector<int> dp(n+1,1e9);
    return sqrRec(n,dp);
}

/*             Tabulation              */
int numSquares(int n) {
    if(n<=0)
        return 0;
    vector<int> dp(n+1,9999);
    dp[0]=0;
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j*j<=i;j++) 
        {
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    return dp[n];
}


int main()
{
    int n=13;
    cout<<numSquares(n);
}