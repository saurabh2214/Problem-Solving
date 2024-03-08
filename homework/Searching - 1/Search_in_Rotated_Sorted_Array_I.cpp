#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(nums[m]==target)
                return m;
            if(nums[s]<=nums[m])
            {
                if(nums[s]<=target && target<=nums[m])
                    e=m-1;
                else
                    s=m+1;
            }
            else
            {
                if(nums[m]<=target && target<=nums[e])
                    s=m+1;
                else
                    e=m-1;
            }
        }
        return -1;
    }

    int main()
    {
        vector<int> ans={4,5,6,7,0,1,2};
        int target=0;
        cout<<search(ans,target)<<endl;
        return 0;
    }