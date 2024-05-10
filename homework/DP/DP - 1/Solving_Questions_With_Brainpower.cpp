#include<bits/stdc++.h>
using namespace std;

/*             memoization              */
long long solve(vector<vector<int>>& questions,int i,vector<long long> &dp)
{
    if(i >= questions.size())
        return 0;
    if(dp[i] != -1)
        return dp[i];
    long long  not_take=solve(questions,i+1,dp);
    long long  take=questions[i][0]+solve(questions,questions[i][1]+i+1,dp);
    return dp[i]=max(take,not_take);
}
long long mostPoints(vector<vector<int>>& questions) {
    int n=questions.size();
    vector<long long> dp(n,-1);
    return solve(questions,0,dp);
}

/*             Tabulation              */
long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> dp(n+1,0);
    for (int i=n-1; i>=0; --i) {
        dp[i] = max(dp[i + 1], questions[i][0] + dp[ min(n, i+1+questions[i][1]) ]);
    }
    return dp[0];        
}

int main()
{
    vector<vector<int>> q={{3,2},{4,3},{4,4},{2,5}};
    cout<<mostPoints(q)<<endl;
    return 0;
}