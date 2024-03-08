#include<bits/stdc++.h>
using namespace std;

int findKRotation(int arr[], int n) {
    int s=0,e=n-1,ans=INT_MAX,res=0;;
    while(s<=e)
    {
        int m=s+(e-s)/2;
        if(arr[s]<=arr[m])
        {
            if(ans>arr[s])
                res=s;
            ans=min(ans,arr[s]);
            s=m+1;
        }
        else
        {
            if(ans>arr[m])
                res=m;
            ans=min(ans,arr[m]);
            e=m-1;
        }
    }
    return res;
    
}

int main()
{
    int arr[]={5, 1, 2, 3, 4};
    int n=5;
    cout<<findKRotation(arr,n)<<endl;
    return 0;
}