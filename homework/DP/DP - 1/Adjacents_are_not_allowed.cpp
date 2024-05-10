#include<bits/stdc++.h>
using namespace std;

/*             memoization              */
int sumRec(int index,vector<vector<int>> mat,vector<int>& dp)
{
    if(index<0)
        return 0;
    if(index==0)
        return max(mat[0][0],mat[1][0]);
    if(dp[index]!=-1)
        return dp[index];
    int take=max(mat[0][index],mat[1][index])+sumRec(index-2,mat,dp);
    int notTake=0+sumRec(index-1,mat,dp);
    return dp[index]=max(take,notTake);
    
}
int maxSum(int N, vector<vector<int>> mat)
{
    vector<int> dp(N+1,-1);
    return sumRec(N-1,mat,dp);
}

/*             Tabulation              */
int maxSum(int N, vector<vector<int>> mat)
{
    vector<int> dp(N+1,0);
    dp[0]=0;
    dp[1] = max(mat[0][0],mat[1][0]);
    for(int i=2;i<=N;i++)
    {
        dp[i] = max(max(mat[0][i-1],mat[1][i-1])+dp[i-2] , dp[i-1]);
    }
    return dp[N] ;  
}

/*           Space Optmized              */
int maxSum(int n, vector<vector<int>> mat)
{
    int f = 0;
    int s = max(mat[0][0],mat[1][0]);
    if(n==1) return s;
    for(int i = 2 ; i <= n ; i++){
        int curr = max(max(mat[0][i-1],mat[1][i-1])+f,s);
        f=s;
        s=curr;
    }
    return s;
}

int main()
{
    vector<vector<int>> mat={{1, 4, 5}, 
       {2, 0, 0}};
    int n=3;
    cout<<maxSum(n,mat)<<endl;
    return 0;
}