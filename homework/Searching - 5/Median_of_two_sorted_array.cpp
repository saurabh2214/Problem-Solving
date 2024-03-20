#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size(),n=nums2.size();
    if(m>n)
        return findMedianSortedArrays(nums2,nums1);
    int low=0,high=m;
    while(low<=high)
    {
        int aMid=low+(high-low)/2;
        int bMid=((m+n+1)/2)-aMid;
        int aLeft=(aMid==0)?INT_MIN:nums1[aMid-1];
        int bLeft=(bMid==0)?INT_MIN:nums2[bMid-1];
        int aRight=(aMid==m)?INT_MAX:nums1[aMid];
        int bRight=(bMid==n)?INT_MAX:nums2[bMid];
        if(aLeft <= bRight && bLeft < aRight)
        {
            if((m + n) % 2 == 1){
                return max(aLeft, bLeft);
            }
            return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
        }
        if(aLeft>bRight)
            high=aMid-1;
        else
            low=aMid+1;
    }
    return -1;
}

int main()
{
    vector<int> nums1={1,3};
    vector<int> nums2={2};
    cout<<findMedianSortedArrays(nums1,nums2)<<endl;
}