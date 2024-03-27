#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int res=0;
int help(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int lh=help(root->left);
    int rh=help(root->right);
    res=max(res,lh+rh);
        return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root) {
    int a=help(root);
    return res;
}


int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    cout<<diameterOfBinaryTree(root)<<endl;
    return 0;
}