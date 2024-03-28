#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int targetsum) {
    if(root==NULL )
        return false;
    if(targetsum==root->val && root->left==NULL && root->right==NULL)
        return true;
    return hasPathSum(root->left,targetsum-root->val)|| hasPathSum(root->right,targetsum-root->val);
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
    root->right->right->right=new TreeNode(1);

    if(hasPathSum(root,22))
        cout<<"Path Found";
    else
        cout<<"NO path Found";
    return 0;
}