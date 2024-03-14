#include<bits/stdc++.h>
using namespace std;

int greaterelement(vector<int>& a,int val)
{
    int low=0,high=a.size(),ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>=val)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        
    }
    if(ans==-1) return 0;
    return a.size()-ans;
}

vector<int> countfunction(vector<int>& a,vector<int>&x)
{
    sort(begin(a),end(a));
    vector<int> res;
    for(int i = 0; i < x.size(); i++)
    {
        res.push_back(greaterelement(a,x[i]));
    }
    return res;
}

int main()
{
    int n=5,q=5;
    vector<int> a={1,2,3,4,5};
    vector<int> x={6,5,4,3,2};
    vector<int> ans=countfunction(a,x);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}