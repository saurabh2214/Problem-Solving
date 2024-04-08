#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void kth(TreeNode* root, int k,int& count,int& ans)
{
    if(root==NULL)
        return ;
    kth(root->left,k,count,ans);
    if(count==k)
        ans=root->val;
    count++;
    kth(root->right,k,count,ans);
}
int kthSmallest(TreeNode* root, int k) {
    int ans=0,count=1;
    kth(root,k,count,ans);
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->left->left->left=new TreeNode(1);
    int k=3;
    cout<<kthSmallest(root,k)<<endl;
    return 0;
}