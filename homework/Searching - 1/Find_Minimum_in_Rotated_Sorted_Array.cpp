#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, result = nums[0];
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < result) 
        {
            right = mid - 1;
            result = nums[mid];
        }
        else 
            left = mid + 1;
    }
    return result;
}

int main()
{
    vector<int> nums={3,4,5,1,2};
    cout<<findMin(nums)<<endl;
    return 0;
}