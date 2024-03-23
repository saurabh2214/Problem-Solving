#include<bits/stdc++.h>
using namespace std;

int Fastoccurance(vector<int>& nums, int target)
{
    int s=0,e=nums.size()-1,ans=-1;
    while(s<=e)
    {
        int m=s+(e-s)/2;
        if(nums[m]==target)
        {
            ans=m;
            e=m-1;
        }
        else if(nums[m]>target)
            e=m-1;
        else
            s=m+1;
    }
    return ans;
}

int Lastoccurance(vector<int>& nums, int target)
{
    int s=0,e=nums.size()-1,ans=-1;
    while(s<=e)
    {
        int m=s+(e-s)/2;
        if(nums[m]==target)
        {
            ans=m;
            s=m+1;
        }
        else if(nums[m]>target)
            e=m-1;
        else
            s=m+1;
    }
    return ans;
}
    
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    ans.emplace_back(Fastoccurance(nums,target));
    ans.emplace_back(Lastoccurance(nums,target));
    return ans;  
}

int main()
{

    vector<int> arr={5,7,7,8,8,10};
    int target=8;
    vector<int> ans=searchRange(arr,target);
    cout<<"The first and last occurrence of "<<target<<" is at index : "<<endl;
    for(auto i: ans)
        cout<<i<<" ";
    return 0;
}