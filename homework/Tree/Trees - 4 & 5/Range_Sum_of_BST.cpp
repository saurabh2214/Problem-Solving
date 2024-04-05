#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int rangeSumBST(TreeNode* root, int low, int high) {
    if(root==NULL)
        return 0;
    int lsum=0,rsum=0,csum=0;
    if(root->val>=low && root->val<=high)
        csum=root->val;
    lsum=rangeSumBST(root->left,low,high);
    rsum=rangeSumBST(root->right,low,high);
    return lsum+rsum+csum;
}

int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(15);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(7);
    root->right->right=new TreeNode(18);
    cout<<rangeSumBST(root,7,15)<<endl;
    return 0;
}