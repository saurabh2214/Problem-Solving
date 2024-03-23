#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& mat, int n, int k)
{
    int low=mat[0][0],high=mat[n-1][n-1];
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int count=0;
        for(int i=0;i<n;i++)
        {
            int up = upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
           count=count+up; 
        }
        if(count>=k)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}

int main()
{
    int n=4;
    vector<vector<int>> mat={{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }};
    int k=3;
    cout<<kthSmallest(mat,n,k)<<endl;
    return 0;
}