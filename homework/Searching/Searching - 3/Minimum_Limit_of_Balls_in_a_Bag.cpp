#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums, int maxOperations,int mid)
{
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] % mid == 0){
            count += (nums[i]/mid) - 1;
        }
        else{
            count += (nums[i]/mid);
        }
        if(count > maxOperations){
            return false;
        }
    }
    if(count > maxOperations){
        return false;
    }
    return true;
}
int minimumSize(vector<int>& nums, int maxOperations) {
    int low=1,high=*max_element(nums.begin(),nums.end());
    int ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(check(nums,maxOperations,mid))
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}

int main()
{
    vector<int> nums={2,4,8,2};
    int maxOperation=4;
    cout<<minimumSize(nums,maxOperation)<<endl;
    return 0;
}