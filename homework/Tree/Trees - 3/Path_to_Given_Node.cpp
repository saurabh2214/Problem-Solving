#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void path(TreeNode* root,int key,vector<int>& ans,vector<int>& v)
{
    if(root == NULL)
        return ;
    v.push_back(root->val);
    if(root->val==key)
    {
        ans=v;
        return ;
    }
    path(root->left,key,ans,v);
    path(root->right,key,ans,v);
    v.pop_back();    
}

vector<int> solve(TreeNode* root,int key)
{
    vector<int> ans;
    vector<int> v;
    path(root,key,ans,v);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int b=5;
    vector<int> ans = solve(root,b);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}