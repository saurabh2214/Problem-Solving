#include<bits/stdc++.h>
using namespace std;
 
bool hasOnlyOneChild(vector<int> pre, int size)
{
    int nextDiff, lastDiff;
 
    for (int i=0; i<size-1; i++)
    {
        nextDiff = pre[i] - pre[i+1];
        lastDiff = pre[i] - pre[size-1];
        if (nextDiff*lastDiff < 0)
            return false;;
    }
    return true;
}

int main()
{
    vector<int> pre = {8, 3, 5, 7, 6};
    int size = 5;
    if (hasOnlyOneChild(pre, size) == true )
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}