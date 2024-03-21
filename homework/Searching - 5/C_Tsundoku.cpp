#include<bits/stdc++.h>
using namespace std;

int countsum(vector<int>& arr,int val)
{
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>val)
            break;
        sum+=arr[i];
    }
    return sum;
}

int cntbooks(vector<int>& arr,int val)
{
    int low=0,high=arr.size()-1;
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

int NoOfBooksRead(int n,vector<int>& A,int m,vector<int>& B,int k)
{
    int low=min(A[0],B[0]);
    int high=max(A[n-1],B[m-1]),ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(countsum(A,mid)+countsum(B,mid)<=k)
        {
            ans=cntbooks(A,mid);
            ans+=cntbooks(B,mid);
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    int n=3,m=4,k=240;
    vector<int> A={60,90,120},B={80,150,80,150};
    cout<<NoOfBooksRead(n,A,m,B,k)<<endl;
    return 0;
}