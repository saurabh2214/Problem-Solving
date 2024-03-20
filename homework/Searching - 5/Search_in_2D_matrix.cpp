#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {   
    int row=matrix.size();
    int col=matrix[0].size();
    int low=0;
    int high=row*col-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        int element = matrix[mid/col][mid%col];
        
        if(element == target)
            return 1;
        else if(element < target)
            low=mid+1;
        else
            high=mid-1;
        
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20}};
    int target=3;
    cout<<searchMatrix(matrix,target)<<endl;
}