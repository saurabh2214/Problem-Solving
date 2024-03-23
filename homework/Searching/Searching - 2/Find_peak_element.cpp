#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int s=1,e=nums.size()-2;
        if(nums[0]>nums[1])
            return 0;
        if(nums[e+1]>nums[e])
            return e+1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1])
                return m;
            if(nums[m]>nums[m-1] && nums[m]<nums[m+1])
                s=m+1;
            else
                e=m-1;
        }
        return -1;
    }

int main()
{
    vector<int> nums={1,2,1,3,5,6,4};
    cout<<findPeakElement(nums);
    return 0;
}