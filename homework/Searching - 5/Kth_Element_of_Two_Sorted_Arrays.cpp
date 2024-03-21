#include<bits/stdc++.h>
using namespace std;

int countSmallArray(vector<int> arr,int val)
{
    int low=0,high=arr.size()-1,ans=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]<=val)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return low;
}

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    int low=min(arr1[0],arr2[0]),high=max(arr1[n-1],arr2[m-1]),ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int count=countSmallArray(arr1,mid);
        count+=countSmallArray(arr2,mid);
        if(count>=k)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1={2,3,6,7,9};
    vector<int> arr2={1,4,8,10};
    int n=5,m=4,k=4;
    cout<<kthElement(arr1,arr2,n,m,k)<<endl;
    return 0;
}