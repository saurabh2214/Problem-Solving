#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if(x==1)
        return 1;
    long long int s=1,e=x/2,ans=0;
    while(s<=e)
    {
        long long int m=s+(e-s)/2;
        if(m*m<=x){
            ans=m;
            s=m+1;
        }
        else
        {
            e=m-1;
        }
    }
    return ans;
}

int main()
{
    cout<<mySqrt(4)<<endl; // Output: 2
    cout<<mySqrt(8)<<endl; // Output: 2
    return 0;
}