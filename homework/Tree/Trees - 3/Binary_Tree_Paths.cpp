#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void path(TreeNode* root,vector<string>& ans,string s)
{
    if(root==NULL)  return;
    if(root->left==NULL && root->right==NULL){
        s+=to_string(root->val);
        ans.push_back(s);
        return ;
    } 
    s+=to_string(root->val)+"->";
    if(root->left!=NULL)
        path(root->left,ans,s);
    if(root->right!=NULL)
        path(root->right,ans,s);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string s;
    path(root,ans,s);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> ans = binaryTreePaths(root);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}