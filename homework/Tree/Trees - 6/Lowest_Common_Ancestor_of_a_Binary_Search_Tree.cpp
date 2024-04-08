#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || root==p||root==q)
        return root;
    TreeNode *lca1=lowestCommonAncestor(root->left,p,q);
    TreeNode *lca2=lowestCommonAncestor(root->right,p,q);
    if(lca1!=NULL && lca2!=NULL)
        return root;
    else if(lca1!=NULL)
        return lca1;
    else
        return lca2;
}

int main()
{
    TreeNode* root=new TreeNode(6);
    root->left=new TreeNode(2);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(7);
    root->right->right=new TreeNode(9);
    root->left->right->left=new TreeNode(3);
    root->left->right->right=new TreeNode(5);

    TreeNode* p=root->left;
    TreeNode* q=root->right;
    TreeNode* lca=lowestCommonAncestor(root,p,q);
    cout<<"LCA of "<<lca->val<<endl;
    return 0;
}