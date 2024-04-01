#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBSTB(TreeNode* root,long long min, long long  max)  
{  
    if (root == NULL)  
        return true;  
    return ( root->val>min && root->val<max && 
        isBSTB(root->left,min,root->val) && isBSTB(root->right,root->val,max));  
}

bool isValidBST(TreeNode* root) {
    if(root->left==NULL && root->right==NULL)
        return true;
    return isBSTB(root,LLONG_MIN,LLONG_MAX);
}

int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if(isValidBST(root)==true)
        cout<<"Valid BST";
    else
        cout<<"Invalid BST";

}