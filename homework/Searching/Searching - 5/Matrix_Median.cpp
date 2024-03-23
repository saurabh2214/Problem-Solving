#include<bits/stdc++.h>
using namespace std;

int countsmall(vector<int>& arr,int val)
{
    int low=0,high=arr.size();
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

int findMedian(vector<vector<int>>& arr)
{
    int n=arr.size();
    int m=arr[0].size();
    int low=INT_MAX,high=INT_MIN,ans=-1;
    for(int i=0;i<n;i++)
    {
        low=min(low,arr[i][0]);
        high=max(high,arr[i][m-1]);
    }
    int half=(n*m)/2;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += countsmall(arr[i], mid);
        }
        if(count>half)
        {
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return  low;

}

int main()
{
    vector<vector<int>> A={{1, 3, 5},{2, 6, 9},{3, 6, 9}};
    cout<<findMedian(A);
    return 0;
}