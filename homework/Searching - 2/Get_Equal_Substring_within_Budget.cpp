#include<bits/stdc++.h>
using namespace std;

bool stringcostcheck(string s,string t,int length,int maxCost)
{
    int cost=0;
    for(int i=0;i<length;i++)
    {
        cost += abs(s[i]-t[i]);
    }
    if(cost<=maxCost)
        return true;
    int j=0;
    for(int i=length;i<s.length();i++)
    {
        cost+=abs(s[i]-t[i]);
        cost-=abs(s[j]-t[j]);
        if(cost<=maxCost) 
            return true;
        j++;
    }
    return false;
}

int equalSubstring(string s, string t, int maxCost) {
    int low=0, high=s.size(),ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(stringcostcheck(s,t,mid,maxCost))
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    string s="abcd",t="bcdf";
    int maxCost=3;
    cout<<equalSubstring(s,t,maxCost)<<endl;
    return 0;

}