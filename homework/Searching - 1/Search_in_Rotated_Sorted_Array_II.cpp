#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
    int s=0;
    int e=nums.size()-1;
    while(s<=e)
    {
        int m=(s+e)/2;
        if(nums[m]==target)
            return true;
        else if(nums[s]<nums[m])
        {
            if(nums[s]<=target && nums[m]>target)
                e=m-1;
            else
                s=m+1;
        }  
        else if(nums[s]==nums[m])
            s++;
        else
        {
            if(nums[m]<target && nums[e]>=target)
                s=m+1;
            else
                e=m-1;
        }  
    }
    return false;
}

int main()
{
    vector<int> ans={2,5,6,0,0,1,2};
    int target=0;
    if(search(ans,target)==true)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
    return 0;
}