#include<bits/stdc++.h>
using namespace std;

/*             memoization              */
int solve(int index,vector<int>&nums,vector<int>&dp){ 
    if(index==0) 
        return nums[index] ;
    if(index<0) 
        return 0 ; 
    
    if(dp[index]!=-1) 
        return dp[index] ;
    int pick = nums[index] ; 
    if(index>1) 
        pick+=solve(index-2,nums,dp); 
    int notpick = solve(index-1,nums,dp); 
    return dp[index]=max(pick,notpick);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n-1,-1),dp2(n-1,-1);
    if(n==1) 
        return nums[0];
    int start=nums[0],end=nums[n-1];
    nums.pop_back();
    int ans1 = solve(n-2,nums,dp);
    for(int i=0;i<n-1;i++) 
        dp[i]=-1;
    nums.push_back(end);
    nums.erase(nums.begin());
    int ans2 = solve(n-2,nums,dp);
    return max(ans1,ans2);
}

/*             Tabulation              */
int tabulation(vector<int>& nums,vector<int>&dp){
    int n = nums.size();
    for(int i=1;i<n;i++){
        int pick = nums[i] ; 
        if(i>1) pick+=dp[i-2] ; 
        int notpick = 0+dp[i-1] ; 
        dp[i]=max(pick,notpick);
    }
    return dp[n-1] ;
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,-1),dp2(n,-1); 
    if(n==1) return nums[0];
    dp[0]=nums[0]; 
    dp2[0]=nums[1];
    vector<int>temp1(nums.begin(),nums.end()-1);
    vector<int>temp2(nums.begin()+1,nums.end());
    int ans1 = tabulation(temp1,dp) ;
    int ans2 = tabulation(temp2,dp2) ;
    return max(ans1,ans2);
}

/*           Space Optmized              */
int tabulationSpaceOp(vector<int>&nums){
    int prev = nums[0] , prev2=0;
    int n = nums.size();
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1) pick+=prev2;
        int notpick=0+prev;
        int curri=max(pick,notpick);
        prev2=prev;
        prev=curri;
    }
    return prev;
}
int rob(vector<int>& nums) {
     int n = nums.size();
    if(n==1) return nums[0];
    vector<int>temp1(nums.begin(),nums.end()-1);
    vector<int>temp2(nums.begin()+1,nums.end());
    int ans1 = tabulationSpaceOp(temp1) ;
    int ans2 = tabulationSpaceOp(temp2) ;
    return max(ans1,ans2);
}

int main()
{
    vector<int> nums={2,3,2};
    cout<<rob(nums)<<endl;
    return 0;
}