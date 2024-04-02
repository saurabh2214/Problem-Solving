#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int size(TreeNode* root)
{
    if(!root)
        return 0;
    return (size(root->left)+size(root->right)+1);
}

bool isBST(TreeNode* root,int mini,int maxi)
{
    if(!root)
        return true;
    if(root->val <= mini or root->val >= maxi)
        return false;
    return (isBST(root->left, mini, root->val) && isBST(root->right, root->val, maxi));
}

int largestBst(TreeNode *root)
{
	if(isBST(root,INT_MIN,INT_MAX)==true)
	    return size(root);
	 return max(largestBst(root->left),largestBst(root->right));
}

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(4);
    root->right=new TreeNode(4);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(8);

    cout<<largestBst(root)<<endl;
    return 0;
}