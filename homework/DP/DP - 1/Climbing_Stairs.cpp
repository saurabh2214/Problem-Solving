#include<bits/stdc++.h>
using namespace std;

/*             memoization              */
int climbRec(int n,vector<int>& dp)
{
    if(n<0)
        return 0;
    if(n==0 || n==1)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    return dp[n]=climbRec(n-1,dp)+climbRec(n-2,dp);
}
int climbStairs(int n) {
    vector<int> dp(n+1,0);
    return climbRec(n,dp);
}

/*             Tabulation              */
int climbStairs(int n) {
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

/*           Space Optmized              */
int climbStairs(int n) {
        int a = 0, b = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }

int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;
}