#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ModTreeNode
{
    bool isbst;
    int min_elmnt;
    int max_elmnt;
    int sum;

    ModTreeNode() {}
    ModTreeNode(bool isbst, int min, int max, int sum)
    {
        this->isbst = isbst;
        this->min_elmnt = min;
        this->max_elmnt = max;
        this->sum = sum;
    }
    
};

int ans = 0;
ModTreeNode *maxsumBST(TreeNode *root, int &ans)
{
    if (root == NULL)
    {
        return new ModTreeNode(true, INT_MAX, INT_MIN, 0);
    }
    ModTreeNode *leftBST = maxsumBST(root->left, ans);
    ModTreeNode *rightBST = maxsumBST(root->right, ans);
    ModTreeNode *root_info = new ModTreeNode();
    root_info->isbst = (leftBST->isbst && rightBST->isbst && (root->val > leftBST->max_elmnt) && (root->val < rightBST->min_elmnt));
    root_info->min_elmnt = min(leftBST->min_elmnt, root->val);
    root_info->max_elmnt = max(rightBST->max_elmnt, root->val);
    root_info->sum = leftBST->sum + rightBST->sum + root->val;
    if (root_info->isbst)
    {
        ans = max(ans, root_info->sum);
    }
    return root_info;
}
int maxSumBST(TreeNode *root)
{
    int maxi = 0;
    ModTreeNode *temp = maxsumBST(root, maxi);
    if (maxi <= 0)
    {
        return 0;
    }
    return maxi;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(4);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(2);
    root->right->right=new TreeNode(5);
    root->right->right->left=new TreeNode(4);
    root->right->right->right=new TreeNode(6);

    cout<<maxSumBST(root)<<endl;
    return 0;
}