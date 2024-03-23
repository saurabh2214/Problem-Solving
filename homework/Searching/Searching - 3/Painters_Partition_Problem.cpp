#include<bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int> &boards,int maxval,int k)
{
    int sum=0,total=0;
    for(auto board:boards)
    {
        sum+=board;
        if(sum>maxval)
        {
            total++;
            sum=board;
        }
    }
    total++;
    return total<=k;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n=boards.size();
    int low=INT_MIN,high=0;
    int ans;
    for(int i=0;i<n;i++)
    {
        if(boards[i]>low)
            low=boards[i];
        high+=boards[i];
    }
    if(k==1)
        return high;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(canAllocate(boards,mid,k))
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
    vector<int> board={2, 1, 5, 6, 2, 3};
    int k=2;
    cout<<findLargestMinDistance(board,k)<<endl;
    return 0;
}