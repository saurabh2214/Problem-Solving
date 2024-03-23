#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int heightOfBinaryTree(TreeNode *root)
{
    if(root==NULL)
        return 0;
    int height=0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        height++;
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
    return height; 
}

int main()
{
    TreeNode* root=new TreeNode(3);
    root->right=new TreeNode(1);
    root->right->left=new TreeNode(2);

    cout<<heightOfBinaryTree(root);


}