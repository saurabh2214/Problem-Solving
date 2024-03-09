#include<bits/stdc++.h>
using namespace std;

bool isPossibleToPlace(vector<int> &stalls,int n,int k,int distance)
{
    int lastPlaced=stalls[0];
    int totalCowsPlaced=1;
    
    for(int i=1;i<n;i++)
    {
        if(stalls[i]-lastPlaced>=distance)
        {
            totalCowsPlaced++;
            lastPlaced=stalls[i];
        }
    }
     return (totalCowsPlaced>=k);
}
int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(),stalls.end());
    int low=1,high=(stalls[n-1]-stalls[0]),ans=1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isPossibleToPlace(stalls,n,k,mid))
        {
            ans=mid;
            low=mid+1;
        }
        else 
            high=mid-1;
    }
    return ans;
}

int main()
{
    int n=5,k=3;
    vector<int> stalls={1,2,4,8,9};
    cout<<solve(n,k,stalls)<<endl;
}