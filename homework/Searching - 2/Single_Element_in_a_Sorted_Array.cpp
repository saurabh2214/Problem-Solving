#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int s=0,e=nums.size()-1;
    if(nums.size()==1)
        return nums[0];
    while(s<=e)
    {
        int m=s+(e-s)/2;
        if(m==nums.size()-1 || m==0)
            return nums[m];
        if(nums[m]!=nums[m+1] && nums[m]!=nums[m-1])
            return nums[m];
        if(nums[m]==nums[m-1] && (m-1)%2==0)
            s=m+1;
        else if(nums[m]!=nums[m-1] && (m)%2==0)
            s=m+1;
        else
            e=m-1;
    }
    return -1;
}

int main()
{
    vector<int> nums={1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(nums);
    return 0;
}