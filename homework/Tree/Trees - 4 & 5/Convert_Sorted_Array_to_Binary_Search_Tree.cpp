#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(vector<int>& nums,int low,int high)
{
    if(low>high)
    {
        return NULL;
    }
    int mid=low+(high-low)/2;
    TreeNode* ans=new TreeNode(nums[mid]);
    ans->left=createTree(nums,low,mid-1);
    ans->right=createTree(nums,mid+1,high);
    return ans;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return createTree(nums,0,nums.size()-1); 
}

int main()
{
    vector<int> nums={-10,-3,0,5,9};
    TreeNode* ans=sortedArrayToBST(nums);
    cout<<ans->val<<endl;
    return 0;
}