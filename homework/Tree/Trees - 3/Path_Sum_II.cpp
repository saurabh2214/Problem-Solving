#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pathsumfunction(TreeNode* root, int targetsum,vector<int>&temp,vector<vector<int>>& ans)
{
    if(root==NULL){
        return;
    }
    if(targetsum==root->val && root->left==NULL && root->right==NULL){
        temp.push_back(root->val);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
    temp.push_back(root->val);
    pathsumfunction(root->left,targetsum-root->val,temp,ans);
    pathsumfunction(root->right,targetsum-root->val,temp,ans);
    temp.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> temp;
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
    pathsumfunction(root,targetSum,temp,ans);
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);
    root->right->right->left=new TreeNode(5);
    root->right->right->right=new TreeNode(1);


    vector<vector<int>> ans=pathSum(root,22);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}