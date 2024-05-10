#include<bits/stdc++.h>
using namespace std;

/*             memoization              */
int RobRec(int ind, vector<int> nums, vector<int> &dp)
{
    if(ind==0)
    {
        return nums[ind];
    }
    if(ind<0)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int pick=nums[ind]+RobRec(ind-2,nums,dp);
    int notPick=0+RobRec(ind-1,nums,dp);
    return dp[ind]=max(pick,notPick);
}
int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,-1);
    return RobRec(n-1,nums,dp);
}

/*             Tabulation              */
int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        int val1=nums[i];
        if(i>1)
        {
            val1+=dp[i-2];
        }
        int val2=0+dp[i-1];
        dp[i]=max(val1,val2);
    }
    return dp[n-1];
}

/*           Space Optmized              */
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
        return nums[0];
    int p_prev=nums[0];
    int prev=max(nums[0],nums[1]);
    int res=prev;
    for(int i=3;i<=n;i++)
    {
        res=max(prev,p_prev+nums[i-1]);
        p_prev=prev;
        prev=res;
    }
    return res;
}


int main()
{
    vector<int> nums={1,2,3,1};
    cout<<rob(nums)<<endl;
    return 0;
}