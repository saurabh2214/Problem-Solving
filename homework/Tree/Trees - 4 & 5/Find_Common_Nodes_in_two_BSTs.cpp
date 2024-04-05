#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder(TreeNode *root,map<int,int>& ans)
{
    if(root==NULL)
        return ;
    preorder(root->left,ans);
    ans[root->val]++;
    preorder(root->right,ans);
}


vector <int> findCommon(TreeNode *root1, TreeNode *root2)
{
    vector<int> res;
    map<int,int> ans;
    preorder(root1,ans);
    preorder(root2,ans);
    for(auto it:ans)
    {
        if(it.second==2)
            res.push_back(it.first);
    }
    return res;
}

int main()
{
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(10);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(7);
    root1->right->left->right= new TreeNode(9);


    TreeNode *root2=new TreeNode(10);
    root2->left = new TreeNode(7);
    root2->right = new TreeNode(20);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(9);

    vector<int> res=findCommon(root1,root2);
    for(auto it:res)
        cout<<it<<" ";
    cout<<endl;
    return 0;

}