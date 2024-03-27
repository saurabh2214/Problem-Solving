#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void rightView(TreeNode* root,int level,vector<int>& ans)
{
    if(root==NULL)
        return;
    if(ans.size()<=level)
    {
        ans.push_back(root->val);
    }
    rightView(root->right,level+1,ans);
    rightView(root->left,level+1,ans);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    rightView(root,0,ans);
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(4);
    vector<int> ans=rightSideView(root);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}