#include<bits/stdc++.h>
using namespace std;

long long power(long long mid,int n,int m)
{
    long long ans=1;
    while(n>0)
    {
        if(ans>m){
            ans=-1;
            break;
        }
        ans*=mid;
        n--;
    }
    return ans;
}

int NthRoot(int n, int m)
{
    if(n==1 || m==1)
        return m;
    long long start=1,end=m/n;
    while(start<=end)
    {
        long long mid=start+(end-start)/2;
        long long value=power(mid,n,m);
        if(value==-1)
           end=mid-1;
        else if(value==m)
            return mid;
        else if(value>m)
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}

int main()
{
    int n=2,m=9;
    cout<<NthRoot(n,m)<<endl;
}