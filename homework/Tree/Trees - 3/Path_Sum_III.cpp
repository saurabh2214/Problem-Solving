#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pathsumfunction(TreeNode* root, int targetsum , map<long long,int>& mp,int& ans,long long& sum)
{
    if(root==NULL)
        return;
    sum+=root->val;
    if(sum==targetsum)
        ans++;
    ans+=mp[sum-targetsum];
    mp[sum]++;
    pathsumfunction(root->left,targetsum,mp,ans,sum);
    pathsumfunction(root->right,targetsum,mp,ans,sum);
    mp[sum]--;
    sum-=root->val;
}
int pathSum(TreeNode* root, int targetSum) {
    map<long long,int> mp;
    long long sum=0;
    int ans=0;
    pathsumfunction(root,targetSum,mp,ans,sum);
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(-3);
    root->right->right=new TreeNode(11);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(2);
    root->left->left->left=new TreeNode(3);
    root->left->left->right=new TreeNode(-2);
    root->left->right->right=new TreeNode(1);


    cout<<pathSum(root,8);
    return 0;
}