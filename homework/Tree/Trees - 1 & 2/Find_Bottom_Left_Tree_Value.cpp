#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode *> q;
    int leftMostval=-1;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* curr=q.front();
        q.pop();
        leftMostval=curr->val;
        if(curr->right!=NULL)
            q.push(curr->right);
        if(curr->left!=NULL)
            q.push(curr->left);
    }
    return  leftMostval;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right= new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);

    cout<<findBottomLeftValue(root)<<endl;
    return 0;
}