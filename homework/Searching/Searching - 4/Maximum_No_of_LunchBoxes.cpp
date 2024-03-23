#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int>& freq,int val,int maxItem)
{
    int totalItem=0;
    for(auto it:freq)
    {
        int currentItem=it/val;
        totalItem+=currentItem;
    }
    return totalItem>=maxItem;
}

int maxLunchBox(int maxItem,vector<int>& arr)
{
    map<int,int> mp;
    for(int i=0;i<arr.size();i++)
        mp[arr[i]]++;
    vector<int> freq;
    for(auto it:mp)
    {
        freq.push_back(it.second);
    }
    int low=0,high=*max_element(freq.begin(),freq.end()),ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(possible(freq,mid,maxItem))
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
    int a=4;
    vector<int> arr={1, 3, 1, 3, 10, 3, 6, 6, 13};
    cout<<maxLunchBox(a,arr)<<endl;
    return 0;
}