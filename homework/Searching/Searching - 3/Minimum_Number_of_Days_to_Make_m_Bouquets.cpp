#include<bits/stdc++.h>
using namespace std;

 int check(vector<int>& bloomDay, int days, int set)
{
    int ans=0,t=0;
    for(int i=0;i<bloomDay.size();i++)
    {
        if(bloomDay[i]>days)
            t=0;
        else
            t++;
        if(t==set){
            ans++;
            t=0;
        }
    }
    return ans;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    if(m>bloomDay.size()/k)   return -1;
    int low=*min_element(bloomDay.begin(),bloomDay.end());
    int high=*max_element(bloomDay.begin(),bloomDay.end());
    while(low<=high)
    {
        int mid = low + ((high - low) >> 1);
        if(check(bloomDay,mid,k)>=m)
        {
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return low;
}

int main()
{
    vector<int> v={7,7,7,7,12,7,7};
    int m=2,k=3;
    cout<<minDays(v,m,k)<<endl;
    return 0;
}