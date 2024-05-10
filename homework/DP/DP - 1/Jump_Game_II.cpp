#include<bits/stdc++.h>
using namespace std;

/*             memoization              */
int jmpRecon(int index, vector<int>& nums, vector<int> &dp)
{
    if(index>=nums.size()-1)
    {
        return 0;
    }
    if(dp[index]!=1e9)
    {
        return dp[index];
    }
    int jmp=1e9;
    for(int i=1;i<=nums[index];i++)
    {
        jmp=min(jmp,1+jmpRecon(index+i,nums,dp));
    }
    return dp[index]=jmp;
}
int jump(vector<int>& nums)
{
    int n=nums.size();
    vector<int> dp(n,1e9);
    return jmpRecon(0,nums,dp);
}

/*             Tabulation              */
int jump(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,1e9);
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=i+nums[i]&& j<n;j++)
        {
            dp[j]=min(dp[j],dp[i]+1);
        }
    }
    return dp[n-1];
}

/*           Space Optmized              */
int jump(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
        return 0;
    if(nums[0]==0)
        return -1;
    int maxReach=0;
    int jump=0;
    int curr=0;
    for(int i=0;i<n;i++)
    {
        maxReach=max(maxReach, i+nums[i]);
        if(maxReach>=n-1)
            return jump+1;
        if(i==curr)
        {
            curr=maxReach;
            jump++;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums={2,3,1,1,4};
    int ans=jump(nums);
    cout<<ans<<endl;
}